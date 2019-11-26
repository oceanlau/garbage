class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) {
            return 0;
        }
        int w = grid[0].size();
        int sum = 0;
        for (int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    sum += 4;
                    if (i > 0 && grid[i-1][j] == 1) {
                        sum--;
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        sum--;
                    }
                    if (i < h - 1 && grid[i+1][j] == 1) {
                        sum--;
                    }
                    if (j < w - 1 && grid[i][j + 1] == 1) {
                        sum--;
                    }
                }
            }
        }
        return sum;
    }
};

class Solution {
private:
    int _dfs(vector<vector<int>>& grid, int h, int w, int i, int j) {
        int sum = 0;
        grid[i][j] = 2;
        if (i == 0) {
            sum += 1;
        } else if (grid[i-1][j] == 0){
            sum += 1;
        } else if (grid[i-1][j] == 1) {
            sum += _dfs(grid, h, w, i - 1, j);
        }
        if (i == h - 1) {
            sum += 1;
        } else if (grid[i+1][j] == 0){
            sum += 1;
        } else if (grid[i+1][j] == 1) {
            sum += _dfs(grid, h, w, i + 1, j);
        }
        if (j == 0) {
            sum += 1;
        } else if (grid[i][j-1] == 0){
            sum += 1;
        } else if (grid[i][j-1] == 1) {
            sum += _dfs(grid, h, w, i, j-1);
        }
        if (j == w - 1) {
            sum += 1;
        } else if (grid[i][j+1] == 0){
            sum += 1;
        } else if (grid[i][j+1] == 1) {
            sum += _dfs(grid, h, w, i, j+1);
        }
        return sum;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) {
            return 0;
        }
        int w = grid[0].size();
        for (int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    return _dfs(grid, h, w, i, j);
                }
            }
        }
        return 0;
    }
};
