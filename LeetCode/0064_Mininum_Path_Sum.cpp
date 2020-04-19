class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) {
            return 0;
        }
        int w = grid[0].size();
        vector<int> dp(w, 0);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0) {
                    if (j == 0) {
                        dp[j] = grid[i][j];
                    } else {
                        dp[j] = grid[i][j] + dp[j - 1];
                    }
                } else if (j == 0) {
                    dp[j] += grid[i][j];
                } else {
                    dp[j] = grid[i][j] + min(dp[j - 1], dp[j]);
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0) {
                    if (j == 0) {
                        continue;
                    }
                    grid[i][j] += grid[i][j-1];
                } else if (j == 0) {
                    grid[i][j] += grid[i-1][j];
                } else {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid[h-1][w-1];
    }
};

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
