class MedianFinder {
private:
    //smaller half in max heap
    priority_queue<int> _maxheap;
    //larger half to the min heap
    priority_queue<int, vector<int>, greater<int>> _minheap;
    int _cnt = 0;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        _cnt++;
        // exchange once to make sure maxheap has smaller nums
        _maxheap.push(num);
        _minheap.push(_maxheap.top());
        _maxheap.pop();
        
        //get size right
        if (_maxheap.size() < _minheap.size()) {
            _maxheap.push(_minheap.top());
            _minheap.pop();
        }
    }
    
    double findMedian() {
        if (_cnt % 2) {
            return _maxheap.top();
        } else {
            return (_maxheap.top() + _minheap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
