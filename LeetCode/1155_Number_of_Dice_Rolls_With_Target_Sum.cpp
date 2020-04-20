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
