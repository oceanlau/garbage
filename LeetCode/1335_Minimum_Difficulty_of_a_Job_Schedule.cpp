class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int> (d + 1, INT_MAX));
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j <= d && j <= i + 1; j ++) {
                int difficulty = jobDifficulty[i];
                for (int k = i; k >= j - 1; k --) {
                    difficulty = max(difficulty, jobDifficulty[k]);
                    if (k == 0) {
                        dp[i][j] = min(dp[i][j], difficulty);
                    } else if (dp[k - 1][j - 1] < INT_MAX){
                        dp[i][j] = min(dp[i][j], difficulty + dp[k - 1][j - 1]);
                    }
                }
            }
        }
        return dp[n - 1][d] == INT_MAX ? -1 : dp[n - 1][d];
    }
};
