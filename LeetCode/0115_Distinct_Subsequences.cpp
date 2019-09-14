//hidden bug

class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.length() > s.length()) {
            return 0;
        }
        if (t.length() == 0 || s.length() == 0) {
            return 1;
        }
        vector<vector<unsigned>> dp(t.length(), vector<unsigned>(s.length(), 0));
        for (int i = 0; i < t.length(); i++) {
            for (int j = 0; j < s.length(); j ++) {
                if (j == 0) {
                    // j == 0 || (j == 0 && i == 0)
                    dp[i][j] = (t[i] == s[j]) ? 1 : 0;
                } else if (i == 0) {
                    // i == 0 except (j == 0 && i == 0)
                    dp[i][j] = (t[i] == s[j]) ? 1 + dp[i][j-1] : dp[i][j-1];
                } else {
                    dp[i][j] = (t[i] == s[j]) ? dp[i][j-1] + dp[i-1][j-1] : dp[i][j-1];
                }
            }
        }
        return dp[t.length() - 1][s.length() - 1];
    }
};
