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
