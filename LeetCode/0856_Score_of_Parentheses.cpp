class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        st.push(0);
        for (const char c : S) {
            if (c == '(') {
                st.push(0);
            } else {
                if (st.top() == 0) {
                    st.pop();
                    st.top() += 1;
                } else {
                    int last = st.top();
                    st.pop();
                    st.top() += 2 * last;
                }
            }
        }
        return st.top();
    }
};
