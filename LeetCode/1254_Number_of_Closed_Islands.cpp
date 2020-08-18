class Solution {
private:
    const vector<vector<int>> _dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void destroy(vector<vector<int>>& grid, int h, int w, int i, int j) {
        if (i >= h || j >= w || i < 0 || j < 0 || grid[i][j] == 1) {
            return;
        }
        grid[i][j] = 1;
        for (const vector<int> _dir : _dirs) {
            destroy(grid, h, w, i + _dir[0], j + _dir[1]);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h < 3) {
            return 0;
        }
        int w = grid[0].size();
        for (int i = 0; i < h; i ++) {
            if (i == 0 || i == h - 1) {
                for (int j = 0; j < w; j++) {
                    destroy(grid, h, w, i, j);
                }
            } else {
                destroy(grid, h, w, i, 0);
                destroy(grid, h, w, i, w - 1);
            }
        }
        int count = 0;
        for (int i = 1; i < h; i ++) {
            for (int j = 1; j < w; j++) {
                if (grid[i][j] == 0) {
                    destroy(grid, h, w, i, j);
                    count ++;
                }
            }
        }
        return count;
    }
};
