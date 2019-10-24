// 64% 100%
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h == 0) {
            return;
        }
        int w = matrix[0].size();
        bool first_col_0 = false;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j< w; j++) {
                if (matrix[i][j] == 0) {
                    if (j == 0) {
                        first_col_0 = true;
                    } else {
                        matrix[0][j] = 0;
                    }
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < h; i++) {
            for (int j = 1; j< w; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < w; j++) {
                matrix[0][j] = 0;
            }
        }
        if (first_col_0) {
            for (int i = 0; i < h; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        int first_row_0 = 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    if (i == 0) {
                        first_row_0 = 0;
                    } else {
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        if (first_row_0 == 0) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
