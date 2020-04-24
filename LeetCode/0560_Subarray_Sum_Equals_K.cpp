class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum_freq;
        presum_freq[0] = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                nums[i] += nums[i- 1];
            }
            ans += presum_freq[nums[i] - k];
            presum_freq[nums[i]] ++;
        }
        return ans;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        unordered_map<int, int> sum_cnt;
        sum_cnt[0] = 1;
        int sum = 0;
        for (const int& num : nums) {
            sum += num;
            if (sum_cnt.count(sum - k)) {
                total += sum_cnt[sum - k];
            }
            sum_cnt[sum] ++;
        }
        return total;
    }
};
