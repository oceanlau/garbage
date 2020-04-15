class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> canhopto {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        int n = 1;
        vector<vector<long long>> dp(N, vector<long long> (10, 0));
        dp[0] = vector<long long> (10, 1);
        while (n <= N - 1) {
            for (int i = 0; i < canhopto.size(); i++) {
                for (int j = 0; j < canhopto[i].size(); j++) {
                    dp[n][i] += dp[n-1][canhopto[i][j]];
                }
                dp[n][i] %= (long long)(pow(10, 9) + 7);
            }
            n ++;
        }
        long long ans = 0;
        for (int i = 0; i < dp[N - 1].size(); i++) {
            ans += dp[N - 1][i];
        }
        return ans % (long long)(pow(10, 9) + 7);
    }
};
