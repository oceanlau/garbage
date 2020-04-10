class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> cumulative_sum;
        int sum = 0;
        cumulative_sum[sum] = -1;
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (cumulative_sum.count(sum - k)) {
                len = max(len, i - cumulative_sum[sum - k]);
            }
            if (!cumulative_sum.count(sum)) {
                cumulative_sum[sum] = i;
            }
        }
        return len;
    }
};

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
