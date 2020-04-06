class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (const int num : nums) {
            sum += num;
        }
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur_sum == sum - nums[i] - cur_sum) {
                return i;
            }
            cur_sum += nums[i];
        }
        return -1;
    }
};
