// TLE
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        int nonpalindrome_len = 0;
        while (true) {
            if (rev.substr(nonpalindrome_len) == s.substr(0, n - nonpalindrome_len)) {
                return rev.substr(0, nonpalindrome_len) + s;
            }
            nonpalindrome_len ++;
        }
        return s;
    }
};
