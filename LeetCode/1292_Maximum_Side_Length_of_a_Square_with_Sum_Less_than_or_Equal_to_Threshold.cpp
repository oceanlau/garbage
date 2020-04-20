class Solution {
private:
    int get_size(vector<vector<int>>& mat, int i, int j, int side) {
        int sz = mat[i + side - 1][j + side - 1];
        if (i > 0) {
            sz -= mat[i - 1][j + side - 1];
        }
        if (j > 0) {
            sz -= mat[i + side - 1][j - 1];
        }
        if (i > 0 && j > 0) {
            sz += mat[i - 1][j - 1];
        }
        return sz;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int max_side_len = 0;
        int h = mat.size();
        int w = mat[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0) {
                    if (j > 0) {
                        mat[i][j] += mat[i][j-1];
                    }
                } else if (j == 0){
                    mat[i][j] += mat[i-1][j];
                } else {
                    mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
                }
            }
        }
        for (int i = 0; i < h - max_side_len; i++) {
            for (int j = 0; j < w - max_side_len; j++) {
                int side = max_side_len + 1;
                while (i + side - 1 < h && j + side - 1 < w && get_size(mat, i, j, side) <= threshold) {
                    max_side_len = side++;
                }
            }
        }
        return max_side_len;
    }
};
