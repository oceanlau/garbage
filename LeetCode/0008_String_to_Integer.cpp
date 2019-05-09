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
