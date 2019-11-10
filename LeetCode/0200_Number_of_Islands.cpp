class Solution {
private:
    void _destroy(vector<vector<char>>& grid, int i, int j, int h, int w) {
        if (i < 0 || i == h || j < 0 || j == w || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        _destroy(grid, i-1, j, h, w);
        _destroy(grid, i, j+1, h, w);
        _destroy(grid, i+1, j, h, w);
        _destroy(grid, i, j-1, h, w);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        int h = grid.size();
        int w = 0;
        if (h > 0) {
            w = grid[0].size();
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '1') {
                    counter++;
                    _destroy(grid, i, j, h, w);
                }
            }
        }
        return counter;
    }
};
