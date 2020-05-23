class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // min largest subarray sum when splitting nums 0-i to j subarrays
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (m + 1, INT_MAX));
        for (int i = 0; i < n; i++) {
            int j = (i == n - 1) ? m : 1;
            for (; (i == n - 1) ? j == m : j < m; j++) {
                // use prev j - 1 to get j at i
                int cur_subarray_sum = 0;
                if (j == 1) {
                    for (int k = i; k >= 0; k--) {
                        cur_subarray_sum += nums[k];
                    }
                    dp[i][j] = cur_subarray_sum;
                } else {
                    // k..i current subarray
                    for (int k = i; k >= j - 1; k--) {
                        cur_subarray_sum += nums[k];
                        dp[i][j] = min(dp[i][j], max(cur_subarray_sum, dp[k - 1][j - 1]));
                    }
                }
            }
        }
        return dp[n - 1][m];
    }
};
