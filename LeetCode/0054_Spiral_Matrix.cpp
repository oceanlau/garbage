//brutal
class Solution {
private:
    void _loop1(vector<vector<int>>& matrix, vector<int>& res, int row, int start, int end) {
        if (start == end) {
            end += 1;
        }
        for (int i = start; i < end; i ++) {
            res.push_back(matrix[row][i]);
        }
    }
    void _loop2(vector<vector<int>>& matrix, vector<int>& res, int col, int start, int end) {
        if (start == end) {
            end += 1;
        }
        for (int i = start; i < end; i ++) {
            res.push_back(matrix[i][col]);
        }
    }
    void _loop3(vector<vector<int>>& matrix, vector<int>& res, int row, int start, int end) {
        if (start == end) {
            end -= 1;
        }
        for (int i = start; i > end; i --) {
            res.push_back(matrix[row][i]);
        }
    }
    void _loop4(vector<vector<int>>& matrix, vector<int>& res, int col, int start, int end) {
        if (start == end) {
            end -= 1;
        }
        for (int i = start; i > end; i --) {
            res.push_back(matrix[i][col]);
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = 0;
        if (m > 0) {
            n = matrix[0].size();
        }
        vector<int> res;
        int side = 0;
        int layer = side / 4;
        int n_start = layer;
        int n_end = n - layer - 1;
        int m_start = layer;
        int m_end = m - layer - 1;
        while (true) {
            if (side / 4 > layer) {
                layer = side / 4;
                n_start = layer;
                n_end = n - layer - 1;
                m_start = layer;
                m_end = m - layer - 1;
            }
            int loop_type = side % 4;
            if (loop_type == 0) {
                if (n_start > n_end || m_start > m_end) {
                    break;
                }
                _loop1(matrix, res, layer, n_start, n_end);
            } else if (loop_type == 1) {
                if (n_start == n_end) {
                    m_start ++;
                }
                if (m_start > m_end) {
                    break;
                }
                _loop2(matrix, res, n_end, m_start, m_end);
            } else if (loop_type == 2) {
                if (n_start > n_end || m_start == m_end) {
                    break;
                }
                _loop3(matrix, res, m_end, n_end, n_start);
            } else if (loop_type == 3) {
                if (m_start > m_end || n_start == n_end) {
                    break;
                }
                _loop4(matrix, res, layer, m_end, m_start);
            }
            side ++;
        }
        
        return res;
    }
};
