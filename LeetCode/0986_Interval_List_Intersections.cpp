class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> results;
        int i = 0;
        int j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i][1] < B[j][0]) {
                i ++;
            } else if (B[j][1] < A[i][0]) {
                j ++;
            } else {
                int right = min(A[i][1], B[j][1]);
                results.push_back({max(A[i][0], B[j][0]), right});
                if (right == A[i][1]) {
                    i ++;
                }
                if (right == B[j][1]) {
                    j ++;
                }
            }
        }
        return results;
    }
};
