class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        if (board.size() == 0) {
            return board;
        }
        int h = board.size();
        int w = board[0].size();
        while (true) {
            bool gameover = true;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (board[i][j] == 0) {
                        continue;
                    }
                    int cur = abs(board[i][j]);
                    if (i + 2 < h) {
                        if (cur == abs(board[i+1][j]) && cur == abs(board[i+2][j])) {
                            gameover = false;
                            board[i][j] = -cur;
                            int row = i + 1;
                            while(row < h && abs(board[row][j]) == cur) {
                                board[row][j] = -cur;
                                row ++;
                            }
                        }
                    }
                    if (j + 2 < w) {
                        if (cur == abs(board[i][j+1]) && cur == abs(board[i][j+2])) {
                            gameover = false;
                            board[i][j] = -cur;
                            int col = j + 1;
                            while(col < w && abs(board[i][col]) == cur) {
                                board[i][col] = -cur;
                                col ++;
                            }
                        }
                    }
                }
            }
            if (gameover) {
                break;
            }
            for (int j = 0; j < w; j++) {
                int pos_i = h - 1;
                int neg_i = h - 1;
                while (pos_i >= 0) {
                    if (board[pos_i][j] > 0) {
                        swap(board[pos_i][j], board[neg_i--][j]);
                    }
                    pos_i --;
                }
                while (neg_i >= 0) {
                    board[neg_i--][j] = 0;
                }
            }
        }
        return board;
    }
};
