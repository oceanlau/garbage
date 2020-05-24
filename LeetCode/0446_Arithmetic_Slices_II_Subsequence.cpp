class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // diff -> count at i. Count includes subseq len >= 2 (not 3)
        vector<unordered_map<int, int>> dp(A.size(), unordered_map<int, int> {});
        int number = 0;
        for (int i = 1; i < A.size(); i++) {
            for (int j = i - 1; j >= 0; j --) {
                long long d = (long long) A[i] - (long long) A[j];
                // will not ever get a len 3 subseq
                if (d <= INT_MIN || d > INT_MAX) {
                    continue;
                }
                int diff = d;
                //len 2
                dp[i][diff] += 1;
                if (dp[j].count(diff)) {
                    number += dp[j][diff]; // got got promoted to len >= 3 because i joins
                    //len >= 3
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return number;
    }
};
