class Solution {
private:
    int _cal_str(string& s, int& i) {
        stack<long long> nums;
        long long num = 0;
        char last_sign = '+';
        // every step only cal a portion of string (to ')')
        while (i < s.length()) {
            char c = s[i];
            if (c == ' ') {
                i ++;
                continue;
            }
            if (isdigit(c)) {
                num = num*10 + (c - '0');
            } else if (c == '(') {
                // recursive call
                num = _cal_str(s, ++i);
            } else {
                if (last_sign == '+') {
                    nums.push(num);
                } else if (last_sign == '-') {
                    nums.push(-num);
                } else if (last_sign == '*') {
                    num = nums.top() * num;
                    nums.pop();
                    nums.push(num);
                } else if (last_sign == '/') {
                    num = nums.top() / num;
                    nums.pop();
                    nums.push(num);
                }
                num = 0;
                if (c == ')') {
                    break;
                }
                last_sign = c;
            }
            i++;
        }
        int sum = 0;
        while (!nums.empty()) {
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }
public:
    int calculate(string s) {
        int i = 0;
        //our algo may skip the last last_sign op without an explicit ending.
        //use a get_num func makes code cleaner and avoids this problem
        s += ')';
        return _cal_str(s, i);
    }
};
