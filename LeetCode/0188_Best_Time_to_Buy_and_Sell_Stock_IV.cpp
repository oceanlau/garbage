class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // each index: buy price - prev profit, sell price - (buy price - prev profit)
        // AT MOST: allow buy and sell on the same day (just waste k)
        
        // hack for leet code
        if (k > prices.size() / 2) {
            k = prices.size() / 2;
        }
        if (prices.empty() || k == 0) {
            return 0;
        }
        vector<pair<int, int>> info(k, {INT_MAX, INT_MIN});
        for (const int p : prices) {
            info[0].first = min(info[0].first, p);
            info[0].second = max(info[0].second, p - info[0].first);
            for (int i = 1; i < info.size(); i ++) {
                info[i].first = min(info[i].first, p - info[i - 1].second);
                info[i].second = max(info[i].second, p - info[i].first);
            }
        }
        return info.back().second;
    }
    
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[i][j] profits when i transactions till day j
        vector<vector<int>> dp(k + 1, vector<int> (prices.size(), -1));
        int max_profit = 0;
        for (int j = 0; j < prices.size(); j ++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= k; i ++) {
            for (int j = i * 2 - 1; j < prices.size(); j ++) {
                for (int last_buy_date = (i - 1) * 2; last_buy_date < j; last_buy_date ++) {
                    if (last_buy_date == 0) {
                        // maybe worse than -1, maybe better
                        dp[i][j] = prices[j] - prices[last_buy_date];
                    } else {
                        // when j - 1 not valid for i transactions, -1
                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                        dp[i][j] = max(dp[i][j], prices[j] - prices[last_buy_date] + dp[i - 1][last_buy_date - 1]);
                    }
                    max_profit = max(max_profit, dp[i][j]);
                }
            }
        }
        return max_profit;
    }
};

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
