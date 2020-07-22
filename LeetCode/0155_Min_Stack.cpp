class MinStack {
private:
    stack<pair<int, int>> st;// val, min val so far
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        int min_so_far = x;
        if (!st.empty() && st.top().second < min_so_far) {
            min_so_far = st.top().second;
        }
        st.emplace(x, min_so_far);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
