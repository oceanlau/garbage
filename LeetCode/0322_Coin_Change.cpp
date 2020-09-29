class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int a = 1; a <= amount; a ++) {
            for (const int c : coins) {
                if (a - c >= 0 && dp[a - c] != -1) {
                    if (dp[a] == -1) {
                        dp[a] = dp[a - c] + 1;
                    } else {
                        dp[a] = min(dp[a], dp[a - c] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
};

class Solution {
private:
    void _bt(vector<int>& coins, vector<int>& dp, int amount) {
        if (amount == 0 || dp[amount] != 0) {
            return;
        }
        int num = INT_MAX;
        for (int i = 0; i < coins.size(); i ++) {
            if (coins[i] > amount) {
                continue;
            }
            _bt(coins, dp, amount - coins[i]);
            if (dp[amount - coins[i]] == -1) {
                continue;
            }
            num = min(num, dp[amount - coins[i]] + 1);
        }
        if (num != INT_MAX) {
            dp[amount] = num;
        } else {
            dp[amount] = -1;
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // min number of coins to get to amount
        vector<int> dp(amount + 1, 0);
        sort(coins.rbegin(), coins.rend());
        _bt(coins, dp, amount);
        return dp[amount];
    }
};

class Solution {
private:
    int _min_coins_to_amount(int amount, vector<int>& coins, vector<int>& cache) {
        if (amount == 0) {
            return 0;
        } else if (amount < 0) {
            return -1;
        } else if (cache[amount] != INT_MAX) {
            return cache[amount];
        }
        for (const int& coin : coins) {
            int num_of_coins = _min_coins_to_amount(amount - coin, coins, cache) + 1;
            if (num_of_coins == 0) {
                continue;
            } else if (num_of_coins < cache[amount]) {
                cache[amount] = num_of_coins;
            }
        }
        if (cache[amount] == INT_MAX) {
            cache[amount] = -1;
        }
        return cache[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        vector<int> cache (amount+1, INT_MAX);
        return _min_coins_to_amount(amount, coins, cache);
    }
};
