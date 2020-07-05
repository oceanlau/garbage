class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[i][j] maxprofit i trans till day j
        // = max(dp[i][j-1], price[j] + (profit_subtract_cost))
        // profit_subtract_cost = max(profit_subtract_cost, dp[i-1][j] - price[j])
        vector<vector<int>> dp (k + 1, vector<int> (prices.size(), 0));
        if (prices.empty()) {
            return 0;
        }
        for (int i = 1; i <= k; i++) {
            int profit_subtract_cost = -prices[0];
            for (int j = 1; j < prices.size(); j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + profit_subtract_cost);
                profit_subtract_cost = max(profit_subtract_cost, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k].back();
    }
};
