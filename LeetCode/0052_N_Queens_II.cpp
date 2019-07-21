class Solution {
private:
    int _total = 0;
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
    void _bt(vector<array<int, 2>>& occupied, int row, int limit) {
        if (row == limit) {
            _total ++;
            return;
        }
        for (int i = 0; i < limit; i++) {
            if (!_is_legal(occupied, row, i)) {
                continue;
            }
            occupied.push_back({row, i});
            _bt(occupied, row + 1, limit);
            occupied.pop_back();
        }
    }
public:
    int totalNQueens(int n) {
        vector<array<int, 2>> occupied;
        _bt(occupied, 0, n);
        return _total;  
    }
};
