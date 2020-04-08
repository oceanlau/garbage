class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return {};
        }
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> res;
        bool up = true;
        pair<int, int> pos = {0, 0};
        while(pos.first >= 0 && pos.first < M && pos.second >= 0 && pos.second < N) {
            res.push_back(matrix[pos.first][pos.second]);
            if (up) {
                if (pos.first - 1 < 0 || pos.second + 1 >= N) {
                    up = false;
                    if (pos.second + 1 >= N) {
                        pos.first ++;
                    } else {
                        pos.second ++;
                    }
                } else {
                    pos.first --;
                    pos.second ++;
                }
            } else {
                if (pos.first + 1 >= M || pos.second - 1 < 0) {
                    up = true;
                    if (pos.first + 1 >= M) {
                        pos.second ++;
                    } else {
                        pos.first ++;
                    }
                } else {
                    pos.first ++;
                    pos.second --;
                }
            }
        }
        return res;
    }
};


// Iterative

// Recursive 53% 28%
class Solution {
private:
    void _traverse(vector<vector<int>>& matrix,
                   int m_h,
                   int m_w,
                   int start_i,
                   int start_j,
                   int dir,
                   vector<int>& res
                  ) {
        if (start_i < 0 || start_i == m_h || start_j < 0 || start_j == m_w) {
            return;
        }
        while (true) {
            res.push_back(matrix[start_i][start_j]);
            if (dir > 0) {
                if (start_i - 1 >= 0 && start_j + 1 != m_w) {
                    start_i --;
                    start_j ++;
                } else {
                    break;
                }
            } else {
                if (start_i + 1 != m_h && start_j - 1 >= 0) {
                    start_i ++;
                    start_j --;
                } else {
                    break;
                }
            }
        }
        if (dir > 0) {
            if (start_j + 1 != m_w) {
                start_j++;
            } else {
                start_i++;
            }
        } else {
            if (start_i + 1 != m_h) {
                start_i++;
            } else {
                start_j ++;
            }
        }
        _traverse(matrix, m_h, m_w, start_i, start_j, -dir, res);
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m_h = matrix.size();
        if (m_h == 0) {
            return res;
        }
        int m_w = matrix[0].size();
        _traverse(matrix, m_h, m_w, 0, 0, +1, res);
        return res;
    }
};
