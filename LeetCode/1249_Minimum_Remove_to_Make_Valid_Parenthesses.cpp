//18% 100%
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> lp_pos;
        for (int i = 0; i != s.length(); i++) {
            if (s[i] == '(') {
                lp_pos.push(i);
            } else if (s[i] == ')') {
                if (lp_pos.size() == 0) {
                    s.erase(s.begin() + i);
                    i --;
                } else {
                    lp_pos.pop();
                }
            }
        }
        while (lp_pos.size() > 0) {
            s.erase(s.begin() + lp_pos.top());
            lp_pos.pop();
        }
        return s;
    }
};
