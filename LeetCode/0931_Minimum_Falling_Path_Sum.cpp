class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.size() == 0) {
            return 0;
        }
        int h = A.size();
        int w = A[0].size();
        vector<int> dp = A[h - 1];
        for (int i = h - 2; i >= 0; i--) {
            vector<int> next = dp;
            if (w > 1) {
                dp[0] = A[i][0] + min(next[0], next[1]);
            } else {
                dp[0] = A[i][0] + next[0];
            }
            for (int j = 1; j < w - 1; j++) {
                int next_min = min(next[j - 1], next[j]);
                next_min = min(next_min, next[j + 1]);
                dp[j] = A[i][j] + next_min;
            }
            if (w > 1) {
                dp[w - 1] = A[i][w - 1] + min(next[w - 2], next[w - 1]);
            } else {
                dp[w - 1] = A[i][w - 1] + next[w - 1];
            }
        }
        int min_val = INT_MAX;
        for (const int val : dp) {
            if (val < min_val) {
                min_val = val;
            }
        }
        return min_val;
    }
};
