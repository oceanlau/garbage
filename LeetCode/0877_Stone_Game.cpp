class Solution {
private:
    vector<vector<int>> dp;
    int get_dp(vector<int>& piles, int l, int r) {
        if (l > r) {
            return -1;
        } else if (l == r) {
            dp[l][r] = piles[l];
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int ifl = piles[l] + max(get_dp(piles, l + 2, r), get_dp(piles, l + 1, r - 1));
        int ifr = piles[r] + max(get_dp(piles, l + 1, r - 1), get_dp(piles, l, r - 2));
        return dp[l][r] = max(ifl, ifr);
    }
public:
    bool stoneGame(vector<int>& piles) {
        // try all combo
        dp = vector<vector<int>> (piles.size(), vector<int> (piles.size(), -1));
        int alex = get_dp(piles, 0, piles.size() - 1);
        int total = 0;
        for (int i = 0; i < piles.size(); i++) {
            total += piles[i];
        }
        return alex > (total - alex);
    }
};
