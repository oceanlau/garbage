//bin search, compare start with start
class MyCalendar {
private:
    vector<pair<int, int>> _events;
    int _search_event (int start) {
        int l = 0;
        int r = _events.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            if (_events[mid].first > start) {
                r = mid - 1;
            } else if (_events[mid].first < start) {
                l = mid + 1;
            } else {
                return -1;
            }
        }
        if (_events[l].first == start || _events[r].first == start) {
            return -1;
        }
        if (_events[l].first > start) {
            return l;
        } else if (_events[r].first > start) {
            return r;
        }
        return r + 1;
    }
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int pos = 0;
        if (_events.size() != 0) {
            pos = _search_event(start);
            if (pos == -1) {
                return false;
            }
            if (pos - 1 >= 0 && _events[pos - 1].second > start) {
                return false;
            }
            //careful!
            if (pos < _events.size() && _events[pos].first < end) {
                return false;
            }
        }
        _events.insert(_events.begin() + pos, make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar {
private:
    // compare end with our start
    // one less compare than comparing start with start
    set<pair<int, int>> _events; // end, start
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto next = _events.upper_bound({start, end}); // only use start
        if (next != _events.end() && next->second < end) {
            //next start < this end
            return false;
        }
        _events.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

//33% 16%
class MyCalendar {
private:
    set<vector<int>> _events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        vector<int> event {start, end};
        if (_events.empty()) {
            _events.insert(event);
            return true;
        }
        auto iter = _events.upper_bound(event);
        if (iter == _events.end()) {
            if ((*--iter)[1] <= event[0]) {
                _events.insert(event);
                return true;
            }
        } else if (iter == _events.begin()){
            if (event[1] <= (*iter)[0]) {
                _events.insert(event);
                return true;
            }
        } else if (event[1] <= (*iter)[0] && (*--iter)[1] <= event[0]) {
            _events.insert(event);
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
