//unclean code 99% 82%, inorder read
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        int cur = 0;
        stack<int> ops;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            int n = c - '0';
            if (n >= 0 && n <= 9) {
                // number: add to current number
                cur = cur * 10 + n;
            } else {
                // +: result+=sign*cur, process stack, cur=0 nextsign=1
                // -: result+=sign*cur, process stack, cur=0 nextsign=-1
                // /: result sign into stack, result 0 sign = 1, read next number, cur = cur / nextnumber
                // *: result sign into stack, result 0 sign = 1, read next number, cur = cur * nextnumber
                if (c == '+' || c == '-') {
                    result += sign*cur;
                    while (!ops.empty()) {
                        sign = ops.top();
                        ops.pop();
                        result = ops.top() + sign*result;
                        ops.pop();
                    }
                    cur = 0;
                    sign = (c == '+' ? 1 : -1);
                } else if (c == '/' || c == '*') {
                    ops.push(result);
                    ops.push(sign);
                    result = 0;
                    sign = 1;
                    i++;
                    int next_number = 0;
                    while (i < s.length() && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') {
                        int n = s[i] - '0';
                        if (n >= 0 && n <= 9) {
                            next_number = next_number * 10 + n;
                        }
                        i++;
                    }
                    if (i < s.length()) {
                        i--;
                    }
                    if (c == '/') {
                        cur /= next_number;
                    } else {
                        cur *= next_number;
                    }
                }
            }
        }
        result += sign*cur;
        while (!ops.empty()) {
            sign = ops.top();
            ops.pop();
            result = ops.top() + sign*result;
            ops.pop();
        }
        return result;
    }
};
