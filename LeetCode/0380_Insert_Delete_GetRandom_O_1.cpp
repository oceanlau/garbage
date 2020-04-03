class RandomizedSet {
private:
    vector<int> els;
    unordered_map<int, int> el_idx;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (el_idx.count(val)) {
            return false;
        }
        els.push_back(val);
        el_idx[val] = els.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!el_idx.count(val)) {
            return false;
        }
        int idx = el_idx[val];
        
        el_idx[els[els.size() - 1]] = idx;
        swap(els[idx], els[els.size() - 1]);
        
        els.pop_back();
        el_idx.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return els[rand() % els.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


class RandomizedSet {
private:
    vector<int> _storage;
    unordered_map<int, int> _m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (_m.count(val)) {
            return false;
        }
        _storage.push_back(val);
        _m[val] = _storage.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!_m.count(val)) {
            return false;
        }
        int target = _m[val];
        int last = _storage.size() - 1;
        swap(_storage[target], _storage[last]);
        _m[_storage[target]] = target;
        _storage.pop_back();
        _m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return _storage[rand() % _storage.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
