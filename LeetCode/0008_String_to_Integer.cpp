class Solution {
public:
    int myAtoi(string str) {
        int sign = 0;
        int val = 0;
        for (const char c : str) {
            if (c == ' ') {
                if (sign != 0) {
                    break;
                }
            } else if (c == '-' || c == '+') {
                if (sign != 0) {
                    break;
                }
                sign = c == '+' ? 1 : -1;
            } else if (isdigit(c)) {
                if (sign == 0) {
                    sign = 1;
                }
                // handles overflow
                if (val > INT_MAX / 10 || (val == INT_MAX / 10 && (c - '0') > INT_MAX % 10)) {
                    if (sign == 1) {
                        return INT_MAX;
                    } else {
                        return INT_MIN;
                    }
                }
                val *= 10;
                val += (c - '0');
            } else {
                break;
            }
        }
        return sign * val;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        int sign = 0;
        int before = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                if (sign != 0) {
                    break;
                }
            } else if (str[i] == '-' || str[i] == '+') {
                if (sign != 0) {
                    break;
                }
                sign = str[i] == '-' ? -1 : 1;
            } else if (str[i] < '0' || str[i] > '9') {
                break;
            } else {
                if (sign == 0) {
                    sign = 1;
                }
                int num = str[i] - '0';
                if (before > INT_MAX / 10 || (before == INT_MAX / 10 && num > INT_MAX % 10)) {
                    if (sign == 1) {
                        return INT_MAX;
                    }
                    return INT_MIN;
                }
                before = before * 10 + num;
            }
        }
        return sign * before;
    }
};


class Solution {
public:
    int myAtoi(string str) {
        short sign = 1;
        unsigned long long r = 0;
        bool must_be_digit = false;
        for(char& c : str) {
            if (must_be_digit && !isdigit(c)) {
                break;
            }
            
            if (c == '-') {
                sign = -1;
                must_be_digit = true;
            } else if (c == '+') {
                must_be_digit = true;
            } else if (isdigit(c)) {
                r = r * 10 + (c - '0');
                must_be_digit = true;
                
                if (r > INT_MAX) {
                    if (sign == 1) {
                        return INT_MAX;
                    // INT_MAX + 1 would overflow
                    } else if (r - 1 > INT_MAX){
                        return INT_MIN;
                    }
                }
                
            } else if (c != ' ') {
                break;
            }
        }

        
        return sign * r;
    }
};
