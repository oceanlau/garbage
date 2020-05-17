class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0) {
            if (S == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        vector<unordered_map<int, int>> dp(nums.size(), unordered_map<int, int> {});
        //careful
        dp[0][nums[0]] += 1;
        dp[0][-nums[0]] += 1;
        for (int i = 1; i < nums.size(); i++) {
            for (const auto& p : dp[i - 1]) {
                dp[i][p.first + nums[i]] += p.second;
                dp[i][p.first - nums[i]] += p.second;
            }
        }
        return dp[nums.size() - 1][S];
    }
};
