//10% 30%
class MyCalendarTwo {
private:
    map<int, int> _times;//start +1, end -1, running sum is active events count
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        _times[start] ++;
        _times[end] --;
        int count = 0;
        for (auto it = _times.begin(); it != _times.end(); it++) {
            count += it->second;
            if (count >= 3) {
                _times[start] --;
                _times[end] ++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
