class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        unordered_map<int, unordered_map<int, int>> ma;
        unordered_map<int, unordered_map<int, int>> mb;
        int l = A.size();
        int m = A[0].size();
        int n = B[0].size();
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] != 0) {
                    ma[i][j] = A[i][j];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (B[i][j] != 0) {
                    mb[i][j] = B[i][j];
                }
            }
        }
        vector<vector<int>> C(l, vector<int>(n, 0));
        for (const auto pla : ma) {
            int li = pla.first;
            for (const auto pma : pla.second) {
                int mi = pma.first;
                if (mb.count(mi)) {
                    for (const auto pnb : mb[mi]) {
                        int ni = pnb.first;
                        C[li][ni] += pma.second * pnb.second;
                    }
                }
            }
        }
        return C;
    }
};
