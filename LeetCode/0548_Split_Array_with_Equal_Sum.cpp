class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) {
            return false;
        }
        vector<int> presum (n, nums[0]);
        for (int i = 1; i < n; i++) {
            presum[i] = presum[i - 1] + nums[i];
        }
        for (int j = 3; j < n - 3; j++) {
            unordered_set<int> quarter_sum;
            for (int i = 1; i < j; i++) {
                if (presum[i - 1] == presum[j - 1] - presum[i]) {
                    quarter_sum.insert(presum[i - 1]);
                }
            }
            for (int k = j + 2; k < n - 1; k++) {
                if (presum[k - 1] - presum[j] == presum[n - 1] - presum[k]) {
                    if (quarter_sum.count(presum[k - 1] - presum[j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
