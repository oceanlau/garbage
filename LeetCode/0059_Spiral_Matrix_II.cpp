class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int val = 1;
        int lvl = 0;
        while (val <= n * n) {
            int i = lvl;
            int j = lvl;
            while (j < n - lvl) {
                matrix[i][j++] = val++;
            }
            i = lvl + 1;
            j = n - lvl - 1;
            while (i < n - lvl) {
                matrix[i++][j] = val++;
            }
            i = n - lvl - 1;
            j = n - lvl - 2;
            while (j >= lvl) {
                matrix[i][j--] = val++;
            }
            i = n - lvl - 2;
            j = lvl;
            while (i >= lvl + 1) {
                matrix[i--][j] = val++;
            }
            lvl ++;
        }
        return matrix;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int row_begin = 0;
        int row_end = n - 1;
        int col_begin = 0;
        int col_end = n - 1;
        int i = 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int t = 0;
        while (row_begin <= row_end && col_begin <= col_end) {
            for (t = col_begin; t <= col_end; t++) {
                matrix[row_begin][t] = i;
                i ++;
            }
            if (++row_begin > row_end) {
                break;
            }
            
            for (t = row_begin; t <= row_end; t++) {
                matrix[t][col_end] = i;
                i ++;
            }
            if (col_begin > --col_end) {
                break;
            }
            
            for (t = col_end; t >= col_begin; t--) {
                matrix[row_end][t] = i;
                i ++;
            }
            if (row_begin > --row_end) {
                break;
            }
            
            for (t = row_end; t >= row_begin; t--) {
                matrix[t][col_begin] = i;
                i ++;
            }
            if (++col_begin > col_end) {
                break;
            }
        }
        return matrix;
        
    }
};
