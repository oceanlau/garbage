class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int if_rob_first = 0;
        int dp_1 = nums[0];
        int dp_2 = 0;
        for (int i = 1; i < nums.size()-1; i++) {
            int tmp = dp_1;
            dp_1 = max(dp_1, nums[i] + dp_2);
            dp_2 = tmp;
        }
        if_rob_first = dp_1;
        
        dp_1 = nums[1];
        dp_2 = 0;
        for (int i = 2; i < nums.size(); i++) {
            int tmp = dp_1;
            dp_1 = max(dp_1, nums[i] + dp_2);
            dp_2 = tmp;
        }
        return max(dp_1, if_rob_first);
    }
};
