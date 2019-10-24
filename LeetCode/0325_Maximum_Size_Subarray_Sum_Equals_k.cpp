class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> sum_to_pos {{0, -1}};
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int diff = sum - k;
            if (sum_to_pos.find(diff) != sum_to_pos.end() && i - sum_to_pos[diff] > res) {
                //res = max(res, i - sum_to_pos[sum - k]); // 10% 60%
                //res = i - sum_to_pos[sum - k]; // 90% 20%
                res = i - sum_to_pos[diff]; // 60% 60%
            }
            if (sum_to_pos.find(sum) == sum_to_pos.end()) {
                sum_to_pos[sum] = i;
            }
        }
        return res;
    }
};
