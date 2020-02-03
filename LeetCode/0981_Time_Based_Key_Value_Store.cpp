class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> _m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        _m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (!_m.count(key)) {
            return "";
        }
        int l = 0;
        int r = _m[key].size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (_m[key][mid].first <= timestamp && _m[key][mid+1].first > timestamp) {
                return _m[key][mid].second;
            } else if (_m[key][mid].first > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (_m[key][l].first <= timestamp) {
            return _m[key][l].second;
        } else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
