class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        vector<unordered_map<int, int>> dp (A.size(), unordered_map<int, int> {}); // LAS ending at i, recording diff -> len
        int longest = 1;
        for (int i = 0; i < A.size(); i++) {
            for (int j = i + 1; j < A.size(); j++) {
                int diff = A[j] - A[i];
                // dont need max here because dp[i][diff] only gets bigger as i gets larger
                dp[j][diff] = dp[i].count(diff) ? dp[i][diff] + 1 : 2;
                longest = max(longest, dp[j][diff]);
            }
        }
        return longest;
    }
};
