class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int len = S.length();
        int maxlen = 0;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j ++) {
                if (S[i] == S[j]) {
                    if (i == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    maxlen = max(maxlen, dp[i][j]);
                }
            }
        }
        return maxlen;
    }
};
