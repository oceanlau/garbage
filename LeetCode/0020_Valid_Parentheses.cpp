// 10/6/19 100% 58.91%
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> lparentheses;
        for (const char c : s) {
            if (map.find(c) != map.end()) {
                if (lparentheses.size() == 0) {
                    return false;
                }
                if (lparentheses.top() != map[c]) {
                    return false;
                }
                lparentheses.pop();
            } else {
                lparentheses.push(c);
            }
        }
        return lparentheses.size() == 0;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for (char& c : s) {
            switch(c) {
                case '{':
                case '[':
                case '(':
                    left.push(c);
                    break;
                case ')':
                    if (left.size() == 0 || left.top() != '(') {
                        return false;
                    }
                    left.pop();
                    break;
                case ']':
                    if (left.size() == 0 || left.top() != '[') {
                        return false;
                    }
                    left.pop();
                    break;
                case '}':
                    if (left.size() == 0 || left.top() != '{') {
                        return false;
                    }
                    left.pop();
                    break;
            }
        }
        if (left.size() > 0) {
            return false;
        }
        return true;
    }
};
