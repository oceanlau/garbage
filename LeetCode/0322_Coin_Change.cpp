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
