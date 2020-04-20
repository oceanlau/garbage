class SnapshotArray {
private:
    vector<vector<pair<int, int>>> _storage;
    int _snap_id = 0;
    int _first_val_let(int index, int snap_id){
        int l = 0;
        int r = _storage[index].size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (_storage[index][mid].first == snap_id) {
                return _storage[index][mid].second;
            } else if (_storage[index][mid].first < snap_id) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (_storage[index][r].first <= snap_id) {
            return _storage[index][r].second;
        }
        return _storage[index][l].second;
    }
public:
    SnapshotArray(int length) {
        _storage = vector<vector<pair<int, int>>>(length, vector<pair<int, int>> {{_snap_id, 0}});
    }
    
    void set(int index, int val) {
        if (_storage[index].back().first == _snap_id) {
            _storage[index].back().second = val;
        } else {
            _storage[index].emplace_back(_snap_id, val);
        }
    }
    
    int snap() {
        return _snap_id++;
    }
    
    int get(int index, int snap_id) {
        return _first_val_let(index, snap_id);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

class SnapshotArray {
private:
    vector<vector<pair<int, int>>> _storage;
    int _snap_id = 0;
    int _bin_search(vector<pair<int, int>>& versions, int snap_id) {
        int l = 0;
        int r = versions.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (versions[mid].first <= snap_id && ( mid + 1 == versions.size() || versions[mid + 1].first > snap_id)) {
                return versions[mid].second;
            } else if (versions[mid].first > snap_id) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (versions[l].first <= snap_id && ( l + 1 == versions.size() || versions[l + 1].first > snap_id)) {
            return versions[l].second;
        }
        if (versions[r].first <= snap_id && ( r + 1 == versions.size() || versions[r + 1].first > snap_id)) {
            return versions[r].second;
        }
        //careful here
        return 0;
    }
public:
    SnapshotArray(int length) {
        _storage.resize(length, vector<pair<int, int>> {});
    }
    
    void set(int index, int val) {
        if (index < 0 || index >= _storage.size()) {
            return;
        }
        if (_storage[index].size() == 0 || _storage[index].back().first != _snap_id) {
            _storage[index].push_back(make_pair(_snap_id, val));
        } else {
            _storage[index].back().second = val;
        }
    }
    
    int snap() {
        return _snap_id++;
    }
    
    int get(int index, int snap_id) {
        if (index < 0 || index >= _storage.size() || snap_id > _snap_id || _storage[index].size() == 0) {
            return 0;
        }
        return _bin_search(_storage[index], snap_id);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
