class Solution {
public:
    int countSubstrings(string s) {
        int cnt = s.length();
        for (int i = 0; i < s.length(); i++) {
            int d = 1;
            int j = i;
            while (j >= 0 && i + d < s.length() && s[j] == s[i+d]) {
                cnt ++;
                j--;
                d++;
            }
            d = 1;
            j = i - 1;
            while (j >= 0 && i + d < s.length() && s[j] == s[i+d]) {
                cnt ++;
                j--;
                d++;
            }
        }
        return cnt;
    }
};
