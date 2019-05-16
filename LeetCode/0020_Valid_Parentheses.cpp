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
