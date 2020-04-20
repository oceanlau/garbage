class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> max_sq_side(w, 0);
        int tmp_diag_sq_side = 0;
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || j == 0) {
                    if (i != 0) {
                        tmp_diag_sq_side = max_sq_side[j];
                    }
                    max_sq_side[j] = matrix[i][j];
                    if (max_sq_side[j] == 1) {
                        cnt ++;
                    }
                } else if (matrix[i][j] == 0) {
                    tmp_diag_sq_side = max_sq_side[j];
                    max_sq_side[j] = 0;
                } else {
                    int neighbor_min_sq_side = min(max_sq_side[j], max_sq_side[j-1]);
                    neighbor_min_sq_side = min(neighbor_min_sq_side, tmp_diag_sq_side);
                    cnt += neighbor_min_sq_side + 1;
                    tmp_diag_sq_side = max_sq_side[j];
                    max_sq_side[j] = neighbor_min_sq_side + 1;
                }
            }
        }
        return cnt;
    }
};
