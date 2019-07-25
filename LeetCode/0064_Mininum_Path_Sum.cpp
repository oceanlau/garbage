class Solution {
private:
    //min sum of m,n
    vector<vector<int>> _dp;
    int _getDp(int m, int n, vector<vector<int>>& grid) {
        if (m == 0 && n == 0) {
            return grid[m][n];
        } else if (_dp[m][n] == -1) {
            if (m == 0) {
                _dp[m][n] = _getDp(m, n - 1, grid) + grid[m][n];
            } else if (n == 0) {
                _dp[m][n] = _getDp(m - 1, n, grid) + grid[m][n];
            } else {
                _dp[m][n] = min(_getDp(m, n - 1, grid), _getDp(m - 1, n, grid)) + grid[m][n];
            }
        }
        
        return _dp[m][n];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        _dp.resize(m, vector<int>(n, -1));
        return _getDp(m - 1, n - 1, grid);
    }
};
