// 61% 82%
class Solution {
private:
    void _impact(vector<vector<int>>& board,
                int board_h,
                int board_w,
                int i,
                int j,
                int y,
                int x) {
        int iy = i + y;
        int jx = j + x;
        if (iy == board_h || jx == board_w || jx < 0) {
            return;
        }
        if (board[i][j] % 2 == 1) {
            board[iy][jx] += 2;
        }
        if (board[iy][jx] % 2 == 1) {
            board[i][j] += 2;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int board_h = board.size();
        if (board_h == 0) {
            return;
        }
        int board_w = board[0].size();
        for (int i = 0; i != board_h; i++) {
            for (int j = 0; j != board_w; j++) {
                _impact(board, board_h, board_w, i, j, 0, 1);
                _impact(board, board_h, board_w, i, j, 1, 1);
                _impact(board, board_h, board_w, i, j, 1, 0);
                _impact(board, board_h, board_w, i, j, 1, -1);
                if (board[i][j] >= 5 && board[i][j] <= 7) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
