class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return 0;
        }
        vector<long long> dp(obstacleGrid[0].size(), 0);
        dp[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i ++) {
            for (int j = 0; j < obstacleGrid[0].size(); j ++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};
