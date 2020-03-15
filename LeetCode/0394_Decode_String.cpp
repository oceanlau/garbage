class Solution {
public:
    string decodeString(string s) {
        if (s == "") {
            return "";
        }
        int k = 0;
        string tmp_str = "";
        // every layer of stack is an operation waiting for ] to trigger
        stack<pair<int, string>> ops;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                if (tmp_str.length() > 0) {
                    pair<int, string> op;
                    if (ops.size() > 0) {
                        op = ops.top();
                        ops.pop();
                    } else {
                        op = make_pair(1, "");
                    }
                    op.second += tmp_str;
                    ops.push(op);
                    tmp_str = "";
                }
                k = k*10 + (s[i] - '0');
            } else if (isalpha(s[i])) {
                tmp_str += s[i];
            } else if (s[i] == '[') {
                ops.push(make_pair(k, ""));
                k = 0;
            } else if (s[i] == ']') {
                pair<int, string> op = ops.top();
                ops.pop();
                op.second += tmp_str;
                tmp_str = "";
                string repeated_str = "";
                while(op.first > 0) {
                    repeated_str += op.second;
                    op.first --;
                }
                if (ops.size() > 0) {
                    op = ops.top();
                    ops.pop();
                    op.second += repeated_str;
                } else {
                    op = make_pair(1, repeated_str);
                }
                ops.push(op);
            }
        }
        if (tmp_str.length() > 0) {
            if (ops.size() > 0) {
                return ops.top().second + tmp_str;
            }
            return tmp_str;
        }
        return ops.top().second;
    }
};
