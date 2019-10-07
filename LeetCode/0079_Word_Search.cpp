// 10/07/19 96.7% 100%
class Solution {
private:
    bool _traverse(vector<vector<char>>& board, string& word, int board_h, int board_w, int word_i, int i, int j) {
        if (word_i == word.length()) {
            return true;
        }
        if (i < 0 || i == board_h || j < 0 || j == board_w) {
            return false;
        }
        if (board[i][j] != word[word_i]) {
            return false;
        }
        char tmp = board[i][j];
        board[i][j] = '.';
        if (_traverse(board, word, board_h, board_w, word_i + 1, i - 1, j) || 
            _traverse(board, word, board_h, board_w, word_i + 1, i, j + 1) ||
            _traverse(board, word, board_h, board_w, word_i + 1, i + 1, j) ||
            _traverse(board, word, board_h, board_w, word_i + 1, i, j - 1)) {
            return true;
        }
        board[i][j] = tmp;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int board_h = board.size();
        if (board_h == 0) {
            return false;
        }
        int board_w = board[0].size();
        for (int i = 0; i != board_h; i++) {
            for (int j = 0; j != board_w; j++) {
                if (_traverse(board, word, board_h, board_w, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
private:
    bool _is_match(vector<vector<char>>& board, int last_match_row, int last_match_col, string& word, int last_word_pos) {
        int next_word_pos = last_word_pos + 1;
        if (next_word_pos == word.length()) {
            return true;
        }
        int up = last_match_row - 1;
        int right = last_match_col + 1;
        int down = last_match_row + 1;
        int left = last_match_col - 1;
        char tmp = word[next_word_pos];
        if (up >= 0 && board[up][last_match_col] == word[next_word_pos]) {
            board[up][last_match_col] = '.';
            if (_is_match(board, up, last_match_col, word, next_word_pos)) {
                return true;
            }
            board[up][last_match_col] = tmp;
        }
        if (right < board[0].size() && board[last_match_row][right] == word[next_word_pos]) {
            board[last_match_row][right] = '.';
            if (_is_match(board, last_match_row, right, word, next_word_pos)) {
                return true;
            }
            board[last_match_row][right] = tmp;
        }
        if (down < board.size() && board[down][last_match_col] == word[next_word_pos]) {
            board[down][last_match_col] = '.';
            if (_is_match(board, down, last_match_col, word, next_word_pos)) {
                return true;
            }
            board[down][last_match_col] = tmp;
        }
        if (left >= 0 && board[last_match_row][left] == word[next_word_pos]) {
            board[last_match_row][left] = '.';
            if (_is_match(board, last_match_row, left, word, next_word_pos)) {
                return true;
            }
            board[last_match_row][left] = tmp;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (!word.length()) {
            return false;
        }
        int row_count = board.size();
        if (row_count == 0) {
            return false;
        }
        int col_count = board[0].size();
        if (col_count == 0) {
            return false;
        }
        //find head
        for(int i = 0; i < row_count; i ++) {
            for(int j = 0; j < col_count; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '.';
                    if (_is_match(board, i, j, word, 0)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
        
    }
};
