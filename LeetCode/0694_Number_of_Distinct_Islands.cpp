// Use str. Much faster! 89% 100%
class Solution {
private:
    void _explore(vector<vector<int>>& grid, int grid_h, int grid_w, int i, int j, stringstream& island, int y, int x) {
        int iy = i + y;
        int jx = j + x;
        if (iy < 0 || iy == grid_h || jx < 0 || jx == grid_w || grid[iy][jx] != 1) {
            return;
        }
        island << y << x;
        grid[iy][jx] = 0;
        _explore(grid, grid_h, grid_w, i, j, island, y - 1, x);
        _explore(grid, grid_h, grid_w, i, j, island, y, x + 1);
        _explore(grid, grid_h, grid_w, i, j, island, y + 1, x);
        _explore(grid, grid_h, grid_w, i, j, island, y, x - 1);
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islands;
        int grid_h = grid.size();
        if (grid_h == 0) {
            return 0;
        }
        int grid_w = grid[0].size();
        for (int i = 0; i != grid_h; i ++) {
            for (int j = 0; j != grid_w; j ++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                stringstream island;
                _explore(grid, grid_h, grid_w, i, j, island, 0, 0);
                islands.insert(island.str());
            }
        }
        return islands.size();
    }
};

// Use set and vector of coords. 30% 14%.
class Solution {
private:
    void _explore(vector<vector<int>>& grid, int grid_h, int grid_w, int i, int j, vector<vector<int>>& island, int y, int x) {
        int iy = i + y;
        int jx = j + x;
        if (iy < 0 || iy == grid_h || jx < 0 || jx == grid_w || grid[iy][jx] != 1) {
            return;
        }
        island.push_back({y, x});
        grid[iy][jx] = 0;
        _explore(grid, grid_h, grid_w, i, j, island, y - 1, x);
        _explore(grid, grid_h, grid_w, i, j, island, y, x + 1);
        _explore(grid, grid_h, grid_w, i, j, island, y + 1, x);
        _explore(grid, grid_h, grid_w, i, j, island, y, x - 1);
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<vector<int>>> islands;
        int grid_h = grid.size();
        if (grid_h == 0) {
            return 0;
        }
        int grid_w = grid[0].size();
        for (int i = 0; i != grid_h; i ++) {
            for (int j = 0; j != grid_w; j ++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                vector<vector<int>> island;
                _explore(grid, grid_h, grid_w, i, j, island, 0, 0);
                islands.insert(island);
            }
        }
        return islands.size();
    }
};
