class Solution {
private:
    void _mark_freedom(vector<vector<char>>& board, int i, int j, int& h, int& w) {
        if (board[i][j] == 'O') {
            board[i][j] = 'F';
            if (i > 0) {
                _mark_freedom(board, i - 1, j, h, w);
            }
            if (i < h-1) {
                _mark_freedom(board, i + 1, j, h, w);
            }
            if (j > 0) {
                _mark_freedom(board, i, j - 1, h, w);
            }
            if (j < w-1) {
                _mark_freedom(board, i, j + 1, h, w);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        if (h == 0) {
            return;
        }
        int w = board[0].size();
        for (int i = 0; i < w; i++) {
            if (board[0][i] == 'O') {
                _mark_freedom(board, 0, i, h, w);
            }
            if (board[h-1][i] == 'O') {
                _mark_freedom(board, h-1, i, h, w);
            }
        }
        for (int i = 0; i < h; i++) {
            if (board[i][0] == 'O') {
                _mark_freedom(board, i, 0, h, w);
            }
            if (board[i][w-1] == 'O') {
                _mark_freedom(board, i, w-1, h, w);
            }
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'F') {
                    board[i][j] = 'O';
                }
                
            }
        }
    }
};
