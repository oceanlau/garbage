class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.length() + 1, vector<int> (text2.length() + 1, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= text1.length(); i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= text2.length(); j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        if (l1 == 0 || l2 == 0) {
            return 0;
        }
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
        for (int i = 0; i <= l1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= l2; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l1][l2];
    }
};
