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
