class Solution {
private:
    bool _is_win(vector<string>& board, char winner) {
        int win_count = 0;
        for(int i = 0; i != 3; i++) {
            if (board[i][0] == winner && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
            if (board[0][i] == winner && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
        }
        if (board[0][0] == winner && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[0][2] == winner && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int x = 0;
        int o = 0;
        for(int i = 0; i != 3; i++) {
            for (int j = 0; j != 3; j++) {
                if (board[i][j] == 'X') {
                    x++;
                } else if (board[i][j] == 'O') {
                    o++;
                }
            }
        }
        if (x == o) {
            return !_is_win(board, 'X');
        } else if (x - o == 1) {
            return !_is_win(board, 'O');
        }
        return false;
    }
};
