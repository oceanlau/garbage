class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 1) {
            return {0};
        }
        vector<int> pre_prod = nums;//first use in left to right pre product. then use as result
        // vector<int> post_prod (nums.size(), 1); // use the original nums
        for (int i = 1; i < nums.size() - 1; i++) { // dont need the last one, but it doesnt matter
            pre_prod[i] *= pre_prod[i-1];
        }
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (j == nums.size() - 1) {
                pre_prod[j] = pre_prod[j-1];
            } else if (j == 0) {
                pre_prod[j] = nums[j+1];
            } else {
                nums[j] *= nums[j+1];
                pre_prod[j] = pre_prod[j-1] * nums[j+1];
            }
        }
        return pre_prod;
    }
};
