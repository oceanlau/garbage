class Solution {
public:
    int minDistance(string word1, string word2) {
        // ops needed to transform prefix of w1 to prefix w2
        vector<vector<int>> dp(word1.length() + 1, vector<int> (word2.length() + 1, INT_MAX));
        for (int i = 0; i <= word1.length(); i++) {
            for (int j = 0; j <= word2.length(); j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else {
                    // delete
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    // insert
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    // replace
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    }
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, INT_MAX));
        for (int i = 0; i < l1 + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < l2 + 1; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i < l1 + 1; i++) {
            for (int j = 1; j < l2 + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);//del
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);//insert
                } else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);//replace
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);//del
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);//insert
                }
            } 
        }
        return dp[l1][l2];
    }
};
