class Solution {
private:
    vector<vector<int>> dirs = vector<vector<int>> {{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    
    void _dfs(vector<vector<char>>& board, int h, int w, int y, int x) {
        int mine_cnt = 0;
        board[y][x] = 'B';
        for (int i = 0; i < dirs.size(); i++) {
            int tmp_y = y + dirs[i][0];
            if (tmp_y >= h || tmp_y < 0) {
                continue;
            }
            int tmp_x = x + dirs[i][1];
            if (tmp_x >= w || tmp_x < 0) {
                continue;
            }
            if (board[tmp_y][tmp_x] == 'M') {
                mine_cnt ++;
            }
        }
        if (mine_cnt > 0) {
            board[y][x] = '0' + mine_cnt;
        } else {
            for (int i = 0; i < dirs.size(); i++) {
                int tmp_y = y + dirs[i][0];
                if (tmp_y >= h || tmp_y < 0) {
                    continue;
                }
                int tmp_x = x + dirs[i][1];
                if (tmp_x >= w || tmp_x < 0) {
                    continue;
                }
                if (board[tmp_y][tmp_x] == 'E') {
                    _dfs(board, h, w, tmp_y, tmp_x);
                }
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int y = click[0];
        int x = click[1];
        if (board[y][x] == 'M') {
            board[y][x] = 'X';
            return board;
        }
        int h = board.size();
        int w = board[0].size();
        _dfs(board, h, w, y, x);
        return board;
    }
};
