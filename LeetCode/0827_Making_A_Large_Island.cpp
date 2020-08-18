class Solution {
private:
    vector<pair<int, int>> _dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int _dfs(vector<vector<int>>& grid, int i, int j, int h, int w, int island_index) {
        if (i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != 1) {
            return 0;
        }
        int cur_size = 1;
        grid[i][j] = island_index;
        for (const pair<int, int>& p : _dirs) {
            cur_size += _dfs(grid, i + p.first, j + p.second, h, w, island_index);
        }
        return cur_size;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> sizes;
        int island_index = 2;
        int h = grid.size();
        if (h == 0) {
            return 0;
        }
        int w = grid[0].size();
        int result = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    int cur_size = _dfs(grid, i, j, h, w, island_index++);
                    sizes.push_back(cur_size);
                    result = max(result, cur_size);
                }
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 0) {
                    int cur_size = 1;
                    unordered_set<int> seen;
                    for (const pair<int, int>& p : _dirs) {
                        int newi = i + p.first;
                        int newj = j + p.second;
                        if (newi < 0 || newi >= h || newj < 0 || newj >= w) {
                            continue;
                        }
                        if (grid[newi][newj] != 0) {
                            int idx = grid[newi][newj];
                            if (!seen.count(idx)) {
                                cur_size += sizes[idx - 2];
                                seen.insert(idx);
                            }
                        }
                    }
                    result = max(result, cur_size);
                }
            }
        }
        return result;
    }
};
