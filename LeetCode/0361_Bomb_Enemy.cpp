class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<int>> row_enemies_cnt (h, vector<int> (w, 0));
        vector<vector<int>> col_enemies_cnt (h, vector<int> (w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 'W') {
                    row_enemies_cnt[i][j] = 0;
                    col_enemies_cnt[i][j] = 0;
                } else if (grid[i][j] == 'E') {
                    row_enemies_cnt[i][j] = (j == 0 ? 0 : row_enemies_cnt[i][j - 1]) + 1;
                    col_enemies_cnt[i][j] = (i == 0 ? 0 : col_enemies_cnt[i - 1][j]) + 1;
                } else {
                    if (j > 0) {
                        row_enemies_cnt[i][j] = row_enemies_cnt[i][j-1];
                    }
                    if (i > 0) {
                        col_enemies_cnt[i][j] = col_enemies_cnt[i-1][j];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = h - 1; i>=0; i--) {
            for (int j = w - 1; j >= 0; j--) {
                if (i < h - 1 && grid[i+1][j] != 'W') {
                    col_enemies_cnt[i][j] = col_enemies_cnt[i+1][j];
                }
                if (j < w - 1 && grid[i][j+1] != 'W') {
                    row_enemies_cnt[i][j] = row_enemies_cnt[i][j+1];
                }
                if (grid[i][j] == '0') {
                    ans = max(ans, col_enemies_cnt[i][j] + row_enemies_cnt[i][j]);
                }
            }
        }
        return ans;
    }
};
