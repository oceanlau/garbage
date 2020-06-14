class Solution {
private:
    int _dfs(vector<vector<int>>& grid, int i, int j) {
        int area = 1;
        grid[i][j] = 0;
        if (i > 0 && grid[i-1][j] == 1) {
            area += _dfs(grid, i-1, j);
        }
        if (j > 0 && grid[i][j-1] == 1) {
            area += _dfs(grid, i, j-1);
        }
        if (i < grid.size() - 1 && grid[i+1][j] == 1) {
            area += _dfs(grid, i+1, j);
        }
        if (j < grid[0].size() - 1 && grid[i][j+1] == 1) {
            area += _dfs(grid, i, j+1);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    maxarea = max(_dfs(grid, i, j), maxarea);
                }
            }
        }
        return maxarea;
    }
};
