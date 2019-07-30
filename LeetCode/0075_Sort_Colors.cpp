class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        for (int i = 0; i <= r;) {
            if (nums[i] > 1) {
                swap(nums[i], nums[r--]);
            } else if (nums[i] < 1) {
                swap(nums[i++], nums[l++]);
            } else {
                i++;
            }
        }
    }
};
