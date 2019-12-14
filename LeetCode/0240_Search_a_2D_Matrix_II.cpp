class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int rows = matrix.size();
        if (matrix[0].size() == 0) {
            return false;
        }
        int cols = matrix[0].size();
        int r = rows - 1;
        int c = 0;
        while (c < cols && r >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                c ++;
            } else {
                r --;
            }
        }
        return false;
    }
};
