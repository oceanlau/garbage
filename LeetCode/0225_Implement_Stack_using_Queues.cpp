// 50% 100%
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        _q.push(x);
        // rotate
        int q_size = _q.size();
        while (q_size > 1) {
            int el = _q.front();
            _q.pop();
            _q.push(el);
            q_size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int el = _q.front();
        _q.pop();
        return el;
    }
    
    /** Get the top element. */
    int top() {
        return _q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _q.empty();
    }
private:
    queue<int> _q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
