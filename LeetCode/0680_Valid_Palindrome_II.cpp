//53% 9%
class Solution {
private:
    bool validPalindrome(string s, int i, int j, int k) {
        while (i < j) {
            if (s[i] != s[j]) {
                if (k > 0) {
                    k --;
                    return validPalindrome(s, i + 1, j, k) || validPalindrome(s, i, j - 1, k);
                } else {
                    return false;
                }
            }
            i ++;
            j --;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        if (s.length() < 2) {
            return true;
        }
        return validPalindrome(s, 0, s.length() - 1, 1);
    }
};
