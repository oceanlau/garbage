class Solution {
private:
    vector<vector<int>> dp;
    int get_dp(vector<int>& piles, int l, int M) {
        if (l >= piles.size()) {
            return 0;
        }
        if (dp[l][M] != -1) {
            return dp[l][M];
        }
        int curMax = INT_MIN;
        for (int i = l; i - l < 2*M && i < piles.size(); i++) {
            curMax = max(curMax, piles[l] - get_dp(piles, i + 1, max(M, i - l + 1)));
        }
        dp[l][M] = curMax;
        return curMax;
    }
public:
    int stoneGameII(vector<int>& piles) {
        dp = vector<vector<int>> (piles.size(), vector<int> (2 * piles.size(), -1));
        vector<int> futuresum = piles;
        for (int i = futuresum.size() - 2; i >= 0; i--) {
            futuresum[i] += futuresum[i + 1];
        }
        return get_dp(futuresum, 0, 1);
    }
};
