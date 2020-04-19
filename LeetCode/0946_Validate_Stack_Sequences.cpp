class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0) {
            return true;
        }
        stack<int> st;
        int j = 0;
        for (int i = 0; i < popped.size(); i++) {
            if (!st.empty() && st.top() == popped[i]) {
                st.pop();
                continue;
            }
            while (j < pushed.size() && pushed[j] != popped[i]) {
                st.push(pushed[j++]);
            }
            if (j == pushed.size()) {
                return false;
            }
            j++;
        }
        return true;
    }
};
