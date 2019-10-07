// 70.92% 16.33%
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int s_size = s.length();
        int i = 0;
        while (i != s_size) {
            res += pow(26, s_size - i - 1) * (s[i] - 'A' + 1);
            i ++;
        }
        return res;
    }
};
