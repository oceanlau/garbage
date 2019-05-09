#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int len = 0;
        int tmp = x;
        while (tmp) {
            tmp /= 10;
            len ++;
        }
        
        int palindrome_num = 0;
        int nth = 1;
        tmp = x;
        while (tmp) {
            palindrome_num += (tmp % 10) * pow(10, len - nth ++);  
            tmp /= 10;
        }
        if (palindrome_num != x) {
            return false;
        }
        return true;
    }
};
