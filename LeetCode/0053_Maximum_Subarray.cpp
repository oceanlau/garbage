class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max_sum = nums[0];
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            current_sum += nums[i];          
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        return max_sum;
    }
};
