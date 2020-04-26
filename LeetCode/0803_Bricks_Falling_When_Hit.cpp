class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    // mark connected (2). return new connection count.
    int _dfs(vector<vector<int>>& grid, int i, int j, int h, int w) {
        grid[i][j] = 2;
        int sum = 1;
        for (const vector<int> d : dirs) {
            int newi = i + d[0];
            int newj = j + d[1];
            if (newi >= 0 && newi < h && newj >= 0 && newj < w && grid[newi][newj] == 1) {
                sum += _dfs(grid, newi, newj, h, w);
            }
        }
        return sum;
    }
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int h = grid.size();
        int w = grid[0].size();
        for (const vector<int> hit : hits) {
            grid[hit[0]][hit[1]] -= 1;
        }
        for (int j = 0; j < w; j++) {
            if (grid[0][j] == 1) {
                _dfs(grid, 0, j, h, w);
            }
        }
        vector<int> results;
        for (int idx = hits.size() - 1; idx >= 0; idx --) {
            int cur_sum = 0;
            int i = hits[idx][0];
            int j = hits[idx][1];
            if (++ grid[i][j] == 1) {
                for (const vector<int> d : dirs) {
                    int newi = i + d[0];
                    int newj = j + d[1];
                    if (i == 0 || (newi >= 0 && newi < h && newj >= 0 && newj < w && grid[newi][newj] == 2)) {
                        cur_sum = _dfs(grid, i, j, h, w) - 1;
                        break;
                    }
                }
            }
            results.push_back(cur_sum);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
