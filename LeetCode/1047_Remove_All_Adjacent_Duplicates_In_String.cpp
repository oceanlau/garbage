class Solution {
public:
    string removeDuplicates(string S) {
        //stack of chars
        stack<char> st;
        for (const char c : S) {
            bool removed = false;
            while (!st.empty() && st.top() == c) {
                st.pop();
                removed = true;
            }
            if (!removed) {
                st.push(c);
            }
        }
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
