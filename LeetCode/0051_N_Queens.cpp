class Solution {
private:
    void _bt(int n, int row, vector<string>& solution, vector<vector<string>>& solutions, vector<bool>& col_occupied, vector<bool>& diag_occupied, vector<bool>& anti_diag_occupied) {
        if (row == n) {
            solutions.push_back(solution);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (col_occupied[col] || diag_occupied[n - row + col] || anti_diag_occupied[row + col]) {
                continue;
            }
            solution[row][col] = 'Q';
            col_occupied[col] = true;
            diag_occupied[n - row + col] = true;
            anti_diag_occupied[row + col] = true;
            _bt(n, row + 1, solution, solutions, col_occupied, diag_occupied, anti_diag_occupied);
            solution[row][col] = '.';
            col_occupied[col] = false;
            diag_occupied[n - row + col] = false;
            anti_diag_occupied[row + col] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // backtrack: each row, each pos
        // if violates rules: col, diag, anti-diag already occupied, skip
        // if not, update
        vector<bool> col_occupied(n, false);
        vector<bool> diag_occupied(2 * n - 1, false);
        vector<bool> anti_diag_occupied(2 * n - 1, false);
        
        vector<string> solution(n, string(n, '.'));
        vector<vector<string>> solutions;
        _bt(n, 0, solution, solutions, col_occupied, diag_occupied, anti_diag_occupied);
        return solutions;
    }
};

class Solution {
private:
    void _bt(int n,
             int row,
             vector<vector<string>>& solutions,
             vector<string>& solution,
             vector<bool>& col_legal,
             vector<bool>& main_diag_legal,
             vector<bool>& sec_diag_legal
            ) {
        if (row == n) {
            solutions.push_back(solution);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (col_legal[i] && main_diag_legal[i + row] && sec_diag_legal[n - i + row]) {
                col_legal[i] = false;
                main_diag_legal[i + row] = false;
                sec_diag_legal[n - i + row] = false;
                string cur_row (n, '.');
                cur_row[i] = 'Q';
                solution.push_back(cur_row);
                _bt(n, row + 1, solutions, solution, col_legal, main_diag_legal, sec_diag_legal);
                col_legal[i] = true;
                main_diag_legal[i + row] = true;
                sec_diag_legal[n - i + row] = true;
                solution.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col_legal(n, true);
        vector<bool> main_diag_legal(2 * n - 1, true);
        vector<bool> sec_diag_legal(2 * n - 1, true);
        vector<string> solution;
        vector<vector<string>> solutions;
        _bt(n, 0, solutions, solution, col_legal, main_diag_legal, sec_diag_legal);
        return solutions;
    }
};

class Solution {
private:
    bool _is_legal(vector<array<int, 2>>& occupied, int x, int y) {
        for (int i = 0; i < occupied.size(); i++) {
            if (y == occupied[i][1]) {
                return false;
            }
            int d = x - occupied[i][0];
            if (d == y - occupied[i][1] || d == occupied[i][1] - y) {
                return false;
            }
            
        }
        return true;
    }
    void _bt(vector<vector<string>>& solutions, vector<string>& solution, vector<array<int, 2>>& occupied, int row, int limit) {
        if (row == limit) {
            solutions.push_back(solution);
            return;
        }
        string solution_row(limit, '.');
        for (int i = 0; i < limit; i++) {
            if (!_is_legal(occupied, row, i)) {
                continue;
            }
            solution_row[i] = 'Q';
            solution.push_back(solution_row);
            occupied.push_back({row, i});
            _bt(solutions, solution, occupied, row + 1, limit);
            occupied.pop_back();
            solution.pop_back();
            solution_row[i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> solution;
        vector<array<int, 2>> occupied;
        _bt(solutions, solution, occupied, 0, n);
        return solutions;
    }
};
