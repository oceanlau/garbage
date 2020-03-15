class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> subboxes(9, unordered_set<char>{});
        vector<unordered_set<char>> cols(9, unordered_set<char>{});
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row.count(board[i][j])) {
                        return false;
                    }
                    if (cols[j].count(board[i][j])) {
                        return false;
                    }
                    if (subboxes[(i/3)*3+j/3].count((board[i][j]))) {
                        return false;
                    }
                    row.insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    subboxes[(i/3)*3+j/3].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};

//slow
class Solution {
private:
    vector<vector<unordered_set<char>>> _maps {
        {{}, {}, {}, {}, {}, {}, {}, {}, {}},
        {{}, {}, {}, {}, {}, {}, {}, {}, {}},
        {{}, {}, {}, {}, {}, {}, {}, {}, {}}
    };
    bool _isRuleValid(int ruleNo, int idx, char num) {
        if (_maps[ruleNo][idx].find(num) != _maps[ruleNo][idx].end()) {
            return false;
        }
        _maps[ruleNo][idx].insert(num);
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i = 0;
        while (i < 9) {
            int j = 0;
            while (j < 9) {
                if (board[i][j] == '.') {          
                    j ++;
                    continue;
                }
                if (!_isRuleValid(0, i, board[i][j])) {
                    return false;
                }
                if (!_isRuleValid(1, j, board[i][j])) {
                    return false;
                }
                int boxIdx = (i / 3) * 3 + (j / 3);
                if (!_isRuleValid(2, boxIdx, board[i][j])) {
                    return false;
                }
                j ++;
            }
            i ++;
        }
        return true;
        
    }
};
