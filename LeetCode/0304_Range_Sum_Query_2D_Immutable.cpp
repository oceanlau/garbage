class NumMatrix {
private:
    vector<vector<int>> sum_matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        int h = matrix.size();
        int w = matrix[0].size();
        sum_matrix = vector<vector<int>> (h, vector<int> (w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0) {
                    if (j == 0) {
                        sum_matrix[i][j] = matrix[i][j];
                    } else {
                        sum_matrix[i][j] = sum_matrix[i][j-1] + matrix[i][j];
                    }
                } else if (j == 0) {
                    sum_matrix[i][j] = sum_matrix[i-1][j] + matrix[i][j];
                } else {
                    sum_matrix[i][j] = sum_matrix[i-1][j] + sum_matrix[i][j-1] - sum_matrix[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sum_matrix[row2][col2];
        if (row1 > 0) {
            sum -= sum_matrix[row1-1][col2];
        }
        if (col1 > 0) {
            sum -= sum_matrix[row2][col1-1];
        }
        if (row1 > 0 && col1 > 0) {
            sum += sum_matrix[row1-1][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

class NumMatrix {
private:
    vector<vector<int>> _presum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        _presum = matrix;
        int h = matrix.size();
        if (h == 0) {
            return;
        }
        int w = matrix[0].size();
        for (int i = h - 1; i >= 0; i --) {
            for (int j = w - 1; j >= 0; j --) {
                if (i == h - 1) {
                    if (j != w - 1) {
                        _presum[i][j] += _presum[i][j + 1];
                    }
                } else if (j == w - 1) {
                    _presum[i][j] += _presum[i + 1][j];
                } else {
                    _presum[i][j] += _presum[i + 1][j] + _presum[i][j + 1] - _presum[i + 1][j + 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int h = _presum.size();
        if (h == 0) {
            return 0;
        }
        int w = _presum[0].size();
        int res = _presum[row1][col1];
        if (row2 < h - 1) {
            res -= _presum[row2 + 1][col1];
        }
        if (col2 < w - 1) {
            res -= _presum[row1][col2 + 1];
            if (row2 < h - 1) {
                res += _presum[row2 + 1][col2 + 1];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
