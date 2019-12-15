class TicTacToe {
private:
    vector<int> _row_counter;
    vector<int> _col_counter;
    int _1st_diag_counter = 0;
    int _2nd_diag_counter = 0;
    int _n = 0;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        _n = n;
        _row_counter = vector<int>(n, 0);
        _col_counter = vector<int>(n, 0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        _row_counter[row] += add;
        _col_counter[col] += add;
        if (row == col) {
            _1st_diag_counter += add;
        }
        if (_n - 1 - col == row) {
            _2nd_diag_counter += add;
        }
        if (abs(_row_counter[row]) == _n
            || abs(_col_counter[col]) == _n
            || abs(_1st_diag_counter) == _n
            || abs(_2nd_diag_counter) == _n
           ) {
            return player == 1 ? 1 : 2;
        } else {
            return 0;
        }
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

class TicTacToe {
private:
    vector<pair<int, int>> _rows;
    vector<pair<int, int>> _cols;
    pair<int, int> _main_diag = make_pair(0, 0);
    pair<int, int> _sec_diag = make_pair(0, 0);
    int _matrix_size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        _rows.resize(n, make_pair(0, 0));
        _cols.resize(n, make_pair(0, 0));
        _matrix_size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            _rows[row].first++;
            if (_rows[row].second == 0 && _rows[row].first == _matrix_size) {
                return 1;
            }
            _cols[col].first++;
            if (_cols[col].second == 0 && _cols[col].first == _matrix_size) {
                return 1;
            }
            if (row == col) {
                _main_diag.first++;
                if (_main_diag.second == 0 && _main_diag.first == _matrix_size) {
                    return 1;
                }
            }
            if (row + col == _matrix_size - 1) {
                _sec_diag.first++;
                if (_sec_diag.second == 0 && _sec_diag.first == _matrix_size) {
                    return 1;
                }
            }
        } else {
            _rows[row].second++;
            if (_rows[row].first == 0 && _rows[row].second == _matrix_size) {
                return 2;
            }
            _cols[col].second++;
            if (_cols[col].first == 0 && _cols[col].second == _matrix_size) {
                return 2;
            }
            if (row == col) {
                _main_diag.second++;
                if (_main_diag.first == 0 && _main_diag.second == _matrix_size) {
                    return 2;
                }
            }
            if (row + col == _matrix_size - 1) {
                _sec_diag.second++;
                if (_sec_diag.first == 0 && _sec_diag.second == _matrix_size) {
                    return 2;
                }
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
