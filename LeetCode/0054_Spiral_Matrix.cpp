class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h == 0) {
            return {};
        }
        int w = matrix[0].size();
        vector<int> dirs {0, 1, 0, -1};// tricky, dont use it in interview
        vector<int> res;
        int i = 0;
        int j = 0;
        while (h > 0 && w > 0) {
            //careful! add first! prevent dupe origin add
            res.push_back(matrix[i][j]);
            int starti = i;
            int startj = j;
            for (int d = 0; d < dirs.size(); d++) {
                // early stop
                if (h == 1) {
                    if (w == 1) {
                        break;
                    }
                    if (d > 0) {
                        break;
                    }
                } else if (w == 1 && d > 1) {
                    break;
                }
                
                int di = d;
                int dj = d + 1;
                if (dj == dirs.size()) {
                    dj = 0;
                }
                //careful! move first! prevent dupe origin add
                i += dirs[di];
                j += dirs[dj];
                while (i >= starti && abs(i - starti) < h && j >= startj && abs(j - startj) < w) {
                    res.push_back(matrix[i][j]);
                    i += dirs[di];
                    j += dirs[dj];
                }
                i -= dirs[di];
                j -= dirs[dj];
            }
            // careful! remove origin, only if a 'square'
            if (h > 1 && w > 1) {
                res.pop_back();
            }
            i ++;
            j ++;
            h -= 2;
            w -= 2;
        }
        return res;
    }
};

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
