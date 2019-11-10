//
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int cur = 0;
        int sign = 1;
        stack<int> ops;
        for (const char c : s) {
            if (isdigit(c)) {
                cur = cur*10 + (c - '0');
            } else {
                result += sign*cur;
                cur = 0;
                if (c == '+') {
                    sign = 1;
                } else if (c == '-') {
                    sign = -1;
                } else if (c == '(') {
                    ops.push(result);
                    ops.push(sign);
                    result = 0;
                    sign = 1;
                } else if (c == ')') {
                    result = ops.top() * result;
                    ops.pop();
                    result += ops.top();
                    ops.pop();
                }
            }
        }
        result += sign*cur;
        return result;
    }
};

// reverse processing. Also avoid -1->-4 trick. The sum could be negative!
class Solution {
public:
    int calculate(string s) {
        stack<string> ops;
        string cur_int = "";
        s = '(' + s + ')';
        int last_c = -1;
        for (int i = s.length()-1; i >= 0; i--) {
            char c = s[i];
            int this_c = c - '0';
            if (this_c >= 0 && this_c <= 9) {
                cur_int = c + cur_int;
            } else {
                // in case two consec empty space. Could also use index-1 of s in this condition.
                if (last_c >= 0 && last_c <= 9) {
                    ops.push(cur_int);
                    cur_int = "";
                }
                if (c == '(') {
                    int tmp = 0;
                    while (ops.top() != ")") {
                        if (ops.top() == "+") {
                            ops.pop();
                            tmp += stoi(ops.top());
                        } else if (ops.top() == "-") {
                            ops.pop();
                            tmp -= stoi(ops.top());
                        } else {
                            tmp = stoi(ops.top());
                        }
                        ops.pop();
                    }
                    ops.pop();//)
                    ops.push(to_string(tmp));
                } else if (c != ' ') {
                    //Bug!
                    //ops.push(""+c);
                    ops.push(string(1, c));
                }
            }
            last_c = this_c;
        }
        return stoi(ops.top());
    }
};

// Wrong thinking. Must from left to right. Else 2-1+2 would be -1.
class Solution {
public:
    int calculate(string s) {
        // -1 +
        // -2 -
        // -3 (
        // -4 )
        stack<int> ops;
        int cur_int = 0;
        s = '(' + s + ')';
        int last_c = -1;
        for (const char c : s) {
            int this_c = c - '0';
            if (this_c >= 0 && this_c <= 9) {
                cur_int = 10*cur_int + this_c;
            } else {
                // in case two consec empty space. Could also use index-1 of s in this condition.
                if (last_c >= 0 && last_c <= 9) {
                    ops.push(cur_int);
                    cur_int = 0;
                }
                if (c == ')') {
                    int tmp = 0;
                    while (ops.top() != -3) {
                        if (ops.top() == -1) {
                            ops.pop();
                            tmp += ops.top();
                        } else if (ops.top() == -2) {
                            ops.pop();
                            tmp = ops.top() - tmp;
                        } else {
                            tmp = ops.top();
                        }
                        ops.pop();
                    }
                    ops.pop();//-3
                    ops.push(tmp);
                } else if (c == '(') {
                    ops.push(-3);
                } else if (c == '-') {
                    ops.push(-2);
                } else if (c == '+') {
                    ops.push(-1);
                }
            }
            last_c = this_c;
        }
        return ops.top();
    }
};
