class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if (h == 0) {
            return 0;
        }
        int w = matrix[0].size();
        vector<int> dp(w, 0);
        int diagonal_neighbor_size = 0;
        int maxside = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    diagonal_neighbor_size = dp[j];
                    dp[j] = matrix[i][j] - '0';
                } else {
                    int possible_size = min(diagonal_neighbor_size, dp[j]);
                    possible_size = min(possible_size, dp[j-1]);
                    
                    diagonal_neighbor_size = dp[j];
                    dp[j] = possible_size + 1;
                }
                maxside = max(maxside, dp[j]);
            }
        }
        return maxside * maxside;
    }
};
