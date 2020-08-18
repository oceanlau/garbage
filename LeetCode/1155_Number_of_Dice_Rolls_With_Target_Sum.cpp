const int MOD = pow(10, 9) + 7;
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // dp[d][target] number of ways
        vector<vector<int>> dp;
        dp.resize(d, vector<int> (target + 1, 0));
        for (int i = 0; i < d; i++) {
            for (int j = 1; j <= target; j++) {
                if (i == 0) {
                    if (j > f) {
                        break;
                    }
                    dp[i][j] = 1;
                    continue;
                }
                int cur = 1;
                while (cur <= min(f, j)) {
                    dp[i][j] += (dp[i - 1][j - cur]) % MOD;
                    dp[i][j] = dp[i][j] % MOD;
                    cur ++;
                }
            }
        }
        return dp[d - 1][target];
    }
};

class Solution {
private:
    vector<vector<int>> _dp;
    int _get_dp(int d, int f, int target) {
        if (_dp[d][target] != -1) {
            return _dp[d][target];
        }
        _dp[d][target] = 0;
        if (d == 0 || target <= 0) {
            return _dp[d][target];
        }
        for (int i = 1; i <= f; i ++) {
            if (i > target) {
                break;
            }
            _dp[d][target] += _get_dp(d - 1, f, target - i);
            _dp[d][target] %= (int)(pow(10, 9) + 7);
        }
        return _dp[d][target];
    };
public:
    int numRollsToTarget(int d, int f, int target) {
        _dp.resize(d + 1, vector<int> (target + 1, -1));
        _dp[0][0] = 1;
        return _get_dp(d, f, target);
    }
};
