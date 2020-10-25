#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <list>
#include <vector>

using namespace std;
template<typename K, typename V, typename H=hash<K>>
class Thread_Safe_Hashtable {
private:
    class Bucket {
    private:
        list<pair<K, V>> _content;

        // Any benefit by returning a const?
        // Why must typename here?
        // const typename list<pair<K, V>>::iterator _find(const K& key) const {
        // const at the end force _content.begin() to return a const_iterator!!!
        typename list<pair<K, V>>::iterator _find(const K& key) {
            typename list<pair<K, V>>::iterator it = _content.begin();
            while (it != _content.end()) {
                if (it->first == key) {
                    break;
                }
                it ++;
            }
            return it;
        }
    public:
        mutable shared_mutex _mutex;
        // 1 insert, 2 update
        // const K, K const. Same thing.
        int insert_or_update(const K& key, const V& val) {
            unique_lock<shared_mutex> lock(_mutex);
            typename list<pair<K, V>>::iterator it = _find(key);
            if (it == _content.end()) {
                //1. data race here. If no lock.
                _content.emplace_back(key, val);
                return 1;
            }
            it->second = val;
            return 2;
        }
        // const at the func end! would need _find to be const too!
        // ref here, bug
        V get(const K& key, const V& default_val) {
            shared_lock<shared_mutex> lock(_mutex);
            // it const, const it, different.
            typename list<pair<K, V>>::iterator it = _find(key);
            if (it == _content.end()) {
                return default_val;
            }
            //2. data race here. If no lock. it may be deleted
            return it->second;
        }
        bool erase(const K& key) {
            unique_lock<shared_mutex> lock(_mutex);
            typename list<pair<K, V>>::iterator it = _find(key);
            if (it == _content.end()) {
                return false;
            }
            //3. data race here. If no lock. it may be deleted. Will this be a problem?
            _content.erase(it);
            return true;
        }
    };
    // Must be unique_ptr?
    vector<unique_ptr<Bucket>> _buckets;
    int _bucket_size = 1;
    H _hash_func;
    // const is not legal here. Not a ptr to const afterall.
    Bucket& _find(const K& key) const {
        // bucket size 0 would throw error here
        const int idx = _hash_func(key) % ((int) _buckets.size());
        return *_buckets[idx];
    }
public:
    Thread_Safe_Hashtable (int bucket_size) : _bucket_size(bucket_size) {
    //Thread_Safe_Hashtable (int bucket_size) : _bucket_size(bucket_size), _buckets(bucket_size) {
        // unique_ptr explicit!! But still bug! Can't use it many times!
        //_buckets.resize(_bucket_size, unique_ptr<Bucket> { new Bucket() });
        _buckets.reserve(_bucket_size);
        for (int i = 0; i < _bucket_size; i ++) {
            _buckets.push_back(make_unique<Bucket>());
            //_buckets[i].reset(new Bucket());
        }
        //cout << _buckets.size() << endl;
    }
    // return const mean anything? Still can be copied right?
    // const at the func end caused another error here!!
    V get(const K& key, const V& default_value=V()) {
        return _find(key).get(key, default_value);
    }
    int insert_or_update(const K& key, const V& val) {
        return _find(key).insert_or_update(key, val);
    }
    bool erase(const K& key) {
        return _find(key).erase(key);
    }
    void resize(int new_bucket_size) {
        vector<unique_lock<shared_mutex>> locks;
        for (int i = 0; i < _bucket_size; i++) {
            locks.push_back(unique_lock<shared_mutex>(_buckets[i]->_mutex));
        }
    }
};
// 4. data race. rehash
// In application code, self-inc usage. Not thread safe. (+=)

int main() {
    Thread_Safe_Hashtable<int, int> tsh(10);
    auto set_and_read = [&tsh]() {
        tsh.insert_or_update(2, 3);
        //cout << tsh.get(2) << endl;
    };
    thread t1(set_and_read);
    thread t2(set_and_read);
    thread t3(set_and_read);
    thread t4(set_and_read);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
