class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int i = matrix.size() - 1;
        int j = 0;
        int w = matrix[0].size();
        while (i >= 0 && j < w) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                j ++;
            } else {
                i --;
            }
        }
        return false;
    }
};


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
