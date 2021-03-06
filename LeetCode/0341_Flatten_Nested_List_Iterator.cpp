/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<const NestedInteger *> _st;
    void _prep_stack() {
        if (_st.empty()) {
            return;
        }
        while (!_st.empty() && !_st.top()->isInteger()) {
            const vector<NestedInteger>& cur_list = _st.top()->getList();
            _st.pop();
            for (int i = cur_list.size() - 1; i >= 0; i --) {
                _st.push(& cur_list[i]);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i --) {
            _st.push(& nestedList[i]);
        }
        _prep_stack();
    }
    
    int next() {
        int cur = _st.top()->getInteger();
        _st.pop();
        _prep_stack();
        return cur;
    }
    
    bool hasNext() {
        return !_st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    //stack to dfs on
    stack<NestedInteger*> nodes;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            nodes.push(&nestedList[i]);
        }
    }

    int next() {
        hasNext();
        int res = nodes.top()->getInteger();
        nodes.pop();
        return res;
    }

    bool hasNext() {
        while(nodes.size() != 0) {
            NestedInteger* cur = nodes.top();
            if (cur->isInteger()) {
                return true;
            }
            nodes.pop();
            vector<NestedInteger>& nestedList = cur->getList();
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                nodes.push(&nestedList[i]);
            }
        }
        return false; 
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
