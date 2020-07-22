class MaxStack {
private:
    list<int> l;
    map<int, vector<list<int>::iterator>> m;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        l.push_back(x);
        auto last_it = l.end();
        m[x].push_back(--last_it);
    }
    
    int pop() {
        int poped = l.back();
        l.pop_back();
        m[poped].pop_back();
        if (m[poped].empty()) {
            m.erase(poped);
        }
        return poped;
    }
    
    int top() {
        return l.back();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int num_to_erase = m.rbegin()->first;
        auto to_erase = m.rbegin()->second.back();
        m.rbegin()->second.pop_back();
        if (m.rbegin()->second.empty()) {
            m.erase(num_to_erase);
        }
        l.erase(to_erase);
        return num_to_erase;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
