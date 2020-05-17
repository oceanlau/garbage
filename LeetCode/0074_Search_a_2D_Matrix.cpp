class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        int l = 0;
        int r = m * n - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (matrix[mid / n][mid % n] == target) {
                return true;
            } else if (matrix[mid / n][mid % n] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (matrix[l / n][l % n] == target) {
            return true;
        }
        if (matrix[r / n][r % n] == target) {
            return true;
        }
        return false;
    }
};

// 94% 51%
class Solution {
private:
    bool _binary_search(vector<int>& row, int start, int end, int target) {
        int mid_pos = (start + end) / 2;
        int mid = row[mid_pos];
        if (mid == target) {
            return true;
        } else if (mid > target && mid_pos - 1 >= start) {
            return _binary_search(row, start, mid_pos - 1, target);
        } else if (mid < target && mid_pos + 1 <= end){
            return _binary_search(row, mid_pos + 1, end, target);
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int end = matrix[0].size() - 1;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == target || matrix[i][end] == target) {
                return true;
            } else if (matrix[i][0] < target && matrix[i][end] > target) {
                return _binary_search(matrix[i], 0, end, target);
            } else if (matrix[i][0] > target) {
                return false;
            }
        }
        return false;
    }
};

// 56% 5%
class Solution {
private:
    bool _binary_search(vector<int> row, int target) {
        int mid_pos = row.size() / 2;
        int mid = row[mid_pos];
        if (mid == target) {
            return true;
        } else if (mid > target && row.begin() + mid_pos < row.end() && mid_pos != 0) {
            return _binary_search(vector<int>(row.begin(), row.begin() + mid_pos), target);
        } else if (mid < target && row.begin() + mid_pos + 1 < row.end()){
            return _binary_search(vector<int>(row.begin() + mid_pos + 1, row.end()), target);
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int end = matrix[0].size() - 1;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == target || matrix[i][end] == target) {
                return true;
            } else if (matrix[i][0] < target && matrix[i][end] > target) {
                return _binary_search(matrix[i], target);
            } else if (matrix[i][0] > target) {
                return false;
            }
        }
        return false;
    }
};
