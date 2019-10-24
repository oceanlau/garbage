// 50% 100%
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _enqueue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        _prepare();
        int el = _dequeue.top();
        _dequeue.pop();
        return el;
    }
    
    /** Get the front element. */
    int peek() {
        _prepare();
        return _dequeue.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _enqueue.empty() && _dequeue.empty();
    }
private:
    stack<int> _enqueue;
    stack<int> _dequeue;
    void _prepare() {
        // dont forget!
        if (_dequeue.size() != 0) {
            return;
        }
        while (_enqueue.size() != 0) {
            int el = _enqueue.top();
            _enqueue.pop();
            _dequeue.push(el);
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
