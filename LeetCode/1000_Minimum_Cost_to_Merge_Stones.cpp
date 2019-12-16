class Solution {
private:
    
    int _get_dp(vector<vector<vector<int>>>& dp, vector<int>& presum, int i, int j, int m, int K) {
        if (dp[i][j][m] != 0) {
            return dp[i][j][m];
        }
        //!!!!!
        /*if ((j - i + 1 - m) % (K - 1)) {
            dp[i][j][m] = -1;
        } else */if (i == j) {
            if (m == 1) {
                dp[i][j][m] = 0;
            } else {
                dp[i][j][m] = -1;
            }
        } else if (m == 1) {
            int merge_K = _get_dp(dp, presum, i, j, K, K);
            if (merge_K == -1) {
                dp[i][j][m] = -1;
            } else {
                int sum = i == 0 ? presum[j] : presum[j] - presum[i-1];
                dp[i][j][m] = merge_K + sum;
            }
        } else {
            int min_cost = INT_MAX;
            //include i and j!(t+1=j)
            for (int t = i; t < j; t++) {
                int l = _get_dp(dp, presum, i, t, m-1, K);
                int r = _get_dp(dp, presum, t+1, j, 1, K);
                if (l != -1 && r != -1) {
                    min_cost = min(min_cost, l + r);
                }
            }
            if (min_cost == INT_MAX) {
                dp[i][j][m] = -1;
            } else {
                dp[i][j][m] = min_cost;
            }
        }
        return dp[i][j][m];
    }
public:
    int mergeStones(vector<int>& stones, int K) {
        int piles_num = stones.size();
        // !!!!
        /*if ((piles_num - 1) % (K - 1) != 0) {
            return -1;
        }*/
        //Minimum cost merging piles from i to j to m pile. (m <= K)
        //dp[i][j][1] = dp[i][j][K] + sum[i][j]
        //dp[i][j][m] = min(dp[i][t][m - 1] + dp[t + 1][j][1]), for t between i and j
        vector<vector<vector<int>>> dp (piles_num, vector<vector<int>> (piles_num, vector<int>(K+1, 0)));
        
        vector<int> presum(piles_num, 0);
        presum[0] = stones[0];
        for (int i = 1; i < piles_num; i++) {
            presum[i] = stones[i] + presum[i-1];
        }
        
        return _get_dp(dp, presum, 0, piles_num - 1, 1, K);
    }
};
