class Solution {
private:
    bool _is_valid(int r, int c, int idx,
                vector<vector<bool>>& col_rule,
                vector<vector<bool>>& row_rule,
                vector<vector<bool>>& block_rule) {
        return !col_rule[c][idx] && !row_rule[r][idx] && !block_rule[(r / 3) * 3 + c / 3][idx];
    }
    bool _solve(vector<vector<int>>& unsolved,
                int i,
                vector<vector<char>>& board,
                vector<vector<bool>>& col_rule,
                vector<vector<bool>>& row_rule,
                vector<vector<bool>>& block_rule) {
        if (i == unsolved.size()) {
            return true;
        }
        int r = unsolved[i][0];
        int c = unsolved[i][1];
        for (char ch = '1'; ch <= '9'; ch++) {
            if (_is_valid(r, c, ch - '1', col_rule, row_rule, block_rule)) {
                board[r][c] = ch;
                col_rule[c][ch - '1'] = true;
                row_rule[r][ch - '1'] = true;
                block_rule[(r / 3) * 3 + c / 3][ch - '1'] = true;
                if (_solve(unsolved, i + 1, board, col_rule, row_rule, block_rule)) {
                    return true;
                }
                board[r][c] = '.';
                col_rule[c][ch - '1'] = false;
                row_rule[r][ch - '1'] = false;
                block_rule[(r / 3) * 3 + c / 3][ch - '1'] = false;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col_rule (9, vector<bool> (9, false));
        vector<vector<bool>> row_rule (9, vector<bool> (9, false));
        vector<vector<bool>> block_rule (9, vector<bool> (9, false));
        vector<vector<int>> unsolved;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    col_rule[j][idx] = true;
                    row_rule[i][idx] = true;
                    block_rule[(i / 3) * 3 + j / 3][idx] = true;
                } else {
                    unsolved.push_back({i, j});
                }
            }
        }
        _solve(unsolved, 0, board, col_rule, row_rule, block_rule);
    }
};

//brute force, no copy
class Solution {
public:
    bool fill(int x, int y, vector<vector<char>>& board, vector<vector<bitset<9>>>& rules) {
        if (board[x][y] != '.') {
            if (y == 8) {
                if (x == 8) {
                    return true;
                } else if (fill(x + 1, 0, board, rules)) {
                    return true;
                }
            } else if (fill(x, y + 1, board, rules)) {
                return true;
            }
        } else {
            //get candidates
            vector<char> candidates_char;
            int box_idx = (x / 3) * 3 + (y / 3);
            bitset<9> candidates_bit = rules[0][x] & rules[1][y] & rules[2][box_idx];
            int i = 0;
            while(i < 9) {
                if (candidates_bit[i]) {
                    candidates_char.push_back(i + 1 + '0');
                }
                i ++;
            }
            for(char candidate : candidates_char) {
                board[x][y] = candidate;
                rules[0][x].reset(candidate - '1');
                rules[1][y].reset(candidate - '1');
                rules[2][box_idx].reset(candidate - '1');
                if (y == 8) {
                    if (x == 8) {
                        return true;
                    } else if (fill(x + 1, 0, board, rules)) {
                        return true;
                    }
                } else if (fill(x, y + 1, board, rules)) {
                    return true;
                }
                board[x][y] = '.';
                rules[0][x].set(candidate - '1');
                rules[1][y].set(candidate - '1');
                rules[2][box_idx].set(candidate - '1');
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        //1 candidate 0 not. Set all 1.
        auto candidates = move(bitset<9>{}.set());
        vector<bitset<9>> candidates_per_rule(9, candidates);
        vector<vector<bitset<9>>> rules(3, candidates_per_rule);

        int i = 0;
        while (i < 9) {
            int j = 0;
            while (j < 9) {
                if (board[i][j] == '.') {
                    j ++;
                    continue;
                }
                rules[0][i].reset(board[i][j] - '1');
                rules[1][j].reset(board[i][j] - '1');
                int box_idx = (i / 3) * 3 + (j / 3);
                rules[2][box_idx].reset(board[i][j] - '1');
                j ++;
            }
            i ++;
        }
        fill(0, 0, board, rules);
    }
};

//brute force
class Solution {
private:
    vector<vector<char>> _board;
public:
    void fill(int x, int y, vector<vector<char>> board, vector<vector<bitset<9>>> rules) {
        if (board[x][y] != '.') {
            if (y == 8) {
                if (x == 8) {
                    _board = board;
                } else {
                    fill(x + 1, 0, board, rules);
                }
            } else {
                fill(x, y + 1, board, rules);
            }
        } else {
            //get candidates
            vector<char> candidates_char;
            int box_idx = (x / 3) * 3 + (y / 3);
            bitset<9> candidates_bit = rules[0][x] & rules[1][y] & rules[2][box_idx];
            int i = 0;
            while(i < 9) {
                if (candidates_bit[i]) {
                    candidates_char.push_back(i + 1 + '0');
                }
                i ++;
            }
            for(char candidate : candidates_char) {
                vector<vector<bitset<9>>> tmp_rules = rules;
                board[x][y] = candidate;
                tmp_rules[0][x].reset(candidate - '1');
                tmp_rules[1][y].reset(candidate - '1');
                tmp_rules[2][box_idx].reset(candidate - '1');
                if (y == 8) {
                    if (x == 8) {
                        _board = board;
                    } else {
                        fill(x + 1, 0, board, tmp_rules);
                    }
                } else {
                    fill(x, y + 1, board, tmp_rules);
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        //1 candidate 0 not. Set all 1.
        auto candidates = move(bitset<9>{}.set());
        vector<bitset<9>> candidates_per_rule(9, candidates);
        vector<vector<bitset<9>>> rules(3, candidates_per_rule);
        
        int i = 0;
        while (i < 9) {
            int j = 0;
            while (j < 9) {
                if (board[i][j] == '.') {
                    j ++;
                    continue;
                }
                rules[0][i].reset(board[i][j] - '1');
                rules[1][j].reset(board[i][j] - '1');
                int box_idx = (i / 3) * 3 + (j / 3);
                rules[2][box_idx].reset(board[i][j] - '1');
                j ++;
            }
            i ++;
        }
        fill(0, 0, board, rules);
        board = _board;
    }
};
