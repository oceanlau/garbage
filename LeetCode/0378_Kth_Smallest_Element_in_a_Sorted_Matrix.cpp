class Solution {
private:
    vector<int> smallerThan(vector<vector<int>>& matrix, int pivot) {
        int n = matrix.size();
        int i = n - 1;
        int j = 0;
        int k = 0;
        int lesser = matrix[0][0];
        int larger = matrix[n-1][n-1];
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= pivot) {
                lesser = max(lesser, matrix[i][j]);
                j ++;
            } else {
                larger = min(larger, matrix[i][j]);
                //careful 
                k += j;
                i --;
            }
        }
        //careful!
        if (j == n) {
            k += (i + 1) * j;
        }
        return {k, lesser, larger};
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        vector<int> res;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            res = smallerThan(matrix, mid);
            if (res[0] == k) {
                return res[1];
            } else if (res[0] > k) {
                r = res[1];
            } else {
                l = res[2];
            }
        }
        res = smallerThan(matrix, l);
        //careful! >=
        if (res[0] >= k) {
            return res[1];
        }
        res = smallerThan(matrix, r);
        return res[1];
    }
};

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
