class Solution {
private:
    int _countSmaller(vector<vector<int>>& matrix, int mid){
        int n = matrix.size();
        int row = n - 1;
        int cnt = 0;
        for (int col = 0; col < n; col++) {
            //smaller or equal! so its >
            while (row >=0 && matrix[row][col] > mid) {
                row--;
            }
            cnt += (row + 1);
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        //cant use r - l > 1 and check l r here.
        //consider [[1,2],[1,3]], k = 1, check l=1, will skip this good answer!
        while (l < r) {
            int mid = l + (r-l) / 2;
            int smaller = _countSmaller(matrix, mid);
            if (smaller < k) {
                l = mid + 1;
            } else { // > or == , find in left including mid, otherwise may skip kth ele! tricky here!
                r = mid;
            }
        }
        return l;
    }
};
