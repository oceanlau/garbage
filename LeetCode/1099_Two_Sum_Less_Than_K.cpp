class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int l = 0;
        int r = A.size() - 1;
        int max_res = -1;
        while (l < r) {
            if (A[l] + A[r] < K) {
                max_res = max(max_res, A[l] + A[r]);
                l++;
            } else {
                r--;
            }
        }
        return max_res;
    }
};
