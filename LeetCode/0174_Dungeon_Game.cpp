// 69% 100%
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int h = dungeon.size();
        if (h == 0) {
            return 1;
        }
        int w = dungeon[0].size();
        // cur health & history min health to get to j, no, may skip optimal result
        //vector<vector<int>> dp(w, vector<int>{0, 0}};
        // tricky: how much health required to get to i,j. Wont help, same reason above. Need to track the sum so far. Still may skip optimal result. Because wont forsee future.
        // tricky: how much health required to get to the end starting at i,j. Guarantee solution
        vector<int> dp (w, 1);
        // Watch out the health is at least 1. Even when all future points are positive.
        for (int i = h - 1; i >= 0; i--) {
            for (int j = w - 1; j >= 0; j--) {
                if (i == h - 1) {
                    if (j == w - 1) {
                        dp[j] = max(1, 1 - dungeon[i][j]);
                    } else {
                        dp[j] = max(1, dp[j + 1] - dungeon[i][j]);
                    }
                } else if (j == w - 1) {
                    dp[j] = max(1, dp[j] - dungeon[i][j]);
                } else {
                    dp[j] = min(dp[j + 1] - dungeon[i][j], dp[j] - dungeon[i][j]);
                    dp[j] = max(1, dp[j]);
                }
            }
        }
        return dp[0];
    }
};
