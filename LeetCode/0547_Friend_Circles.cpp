class Solution {
private:
    void _dfs(vector<vector<int>>& M, int i) {
        M[i][i] = 0;
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] == 1 && M[j][j] == 1) {
                _dfs(M, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int cnt = 0;
        for (int i = 0; i < M.size(); i++) {
            if (M[i][i] == 1) {
                _dfs(M, i);
                cnt ++;
            }
        }
        return cnt;
    }
};
