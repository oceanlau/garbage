class Solution {
private:
    vector<int> _dp;
    int _getDp(int n) {
        if (!_dp[n]) {
            _dp[n] = _getDp(n - 1) + _getDp(n - 2);
        }
        return _dp[n];
    };
public:
    int climbStairs(int n) {
        _dp.resize(n, 0);
        _dp[0] = 1;
        if (n > 1) {    
            _dp[1] = 2;
        }
        return _getDp(n - 1);
    }
};
