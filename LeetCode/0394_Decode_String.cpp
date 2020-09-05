class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;
        st.emplace(1, "");
        int num = 0;
        for (const char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (isalpha(c)) {
                st.top().second += c;
            } else if (c == '[') {
                st.emplace(num, "");
                num = 0;
            } else {
                pair<int, string> cur = st.top();
                st.pop();
                while (cur.first > 0) {
                    st.top().second += cur.second;
                    cur.first --;
                }
            }
        }
        pair<int, string> cur = st.top();
        string decoded = "";
        while (cur.first > 0) {
            decoded += cur.second;
            cur.first --;
        }
        return decoded;
    }
};

class Solution {
private:
    string decompress(string s, int& i) {
        int num = 0;
        string cur = "";
        while (i < s.length()) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                i ++;
                string child = decompress(s, i);
                while (num > 0) {
                    cur += child;
                    num --;
                }
            } else if (s[i] == ']') {
                break;
            } else {
                cur += s[i];
            }
            i ++;
        }
        return cur;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return decompress(s, i);
    }
};

class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;
        st.emplace(1, "");
        int repeat = 0;
        for (const char c : s) {
            if (isdigit(c)) {
                repeat = repeat * 10 + (c - '0');
            } else if (c == '[') {
                st.emplace(repeat, "");
                repeat = 0;
            } else if (c == ']') {
                auto last = st.top();
                st.pop();
                string last_string = "";
                while (last.first > 0) {
                    last_string += last.second;
                    last.first --;
                }
                st.top().second += last_string;
            } else {
                st.top().second += c;
            }
        }
        return st.top().second;
    }
};

class Solution {
public:
    string decodeString(string s) {
        // ]: pop stack, merge into last stack
        // [: put number and empty string into stack
        // isalpha: append to top of stack
        // init stack with 1, ""
        int num = 0;
        stack<pair<int, string>> st;
        st.emplace(1, "");
        for (const char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                st.emplace(num, "");
                num = 0;
            } else if (c == ']') {
                auto last = st.top();
                st.pop();
                string tmp = "";
                while (last.first > 0) {
                    last.first --;
                    tmp += last.second;
                }
                st.top().second += tmp;
            } else {
                st.top().second += c;
            }
        }
        return st.top().second;
    }
};

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
