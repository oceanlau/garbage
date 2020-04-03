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
