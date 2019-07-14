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
