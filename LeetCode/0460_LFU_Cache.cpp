struct Node {
    int key;
    int val;
    int freq;
};
class LFUCache {
private:
    unordered_map<int, list<Node*>::iterator> _k_m;
    unordered_map<int, list<Node*>> _freq_m;
    int _capacity = 0;
    int _current = 0;
    int _min_freq = 1;
public:
    LFUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (_k_m.count(key)) {
            int res = (*_k_m[key])->val;
            int freq = (*_k_m[key])->freq;
            int last_freq_list_size = _freq_m[freq].size();
            _freq_m[freq + 1].splice(_freq_m[freq + 1].begin(), _freq_m[freq], _k_m[key]);
            (*_k_m[key])->freq++;
            if (--last_freq_list_size == 0) {
                if (freq == _min_freq) {
                    _min_freq ++;
                }
                _freq_m.erase(freq);
            }
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (_capacity == 0) {
            return;
        }
        if (_k_m.count(key)) {
            int freq = (*_k_m[key])->freq;
            int last_freq_list_size = _freq_m[freq].size();
            _freq_m[freq + 1].splice(_freq_m[freq + 1].begin(), _freq_m[freq], _k_m[key]);
            (*_k_m[key])->freq++;
            (*_k_m[key])->val = value;
            if (--last_freq_list_size == 0) {
                if (freq == _min_freq) {
                    _min_freq ++;
                }
                _freq_m.erase(freq);
            }
        } else {
            if (_capacity == _current) {
                int last_freq_list_size = _freq_m[_min_freq].size();
                Node* node_to_delete = _freq_m[_min_freq].back();
                _freq_m[_min_freq].pop_back();
                _k_m.erase(node_to_delete->key);
                if (--last_freq_list_size == 0) {
                    _freq_m.erase(_min_freq);
                }
                _current --;
            }
            _min_freq = 1;
            Node* node_to_add = new Node();
            node_to_add->key = key;
            node_to_add->val = value;
            node_to_add->freq = _min_freq;
            _freq_m[_min_freq].push_front(node_to_add);
            _k_m[key] = _freq_m[_min_freq].begin();
            _current ++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
