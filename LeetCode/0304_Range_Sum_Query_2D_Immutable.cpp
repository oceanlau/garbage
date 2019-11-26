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
