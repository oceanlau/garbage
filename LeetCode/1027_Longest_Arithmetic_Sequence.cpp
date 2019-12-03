class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int ans = 2;
        vector<unordered_map<int, int>> dp(A.size(), unordered_map<int, int> {}); // pos -> diff -> length(the answer)
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
            //the order matters!
            //for (int j = i - 1; j >= 0; j--) {
                int diff = A[i] - A[j];
                if (dp[j].count(diff)) {
                    dp[i][diff] = dp[j][diff] + 1;
                } else {
                    dp[i][diff] = 2;
                }
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
