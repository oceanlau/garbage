class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            int missing_cnt = nums[mid] - nums[0] - mid;
            if (missing_cnt >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        int r_missing_cnt = nums[r] - nums[0] - r;
        if (r_missing_cnt >= k) {
            return nums[r] - (r_missing_cnt - k + 1);
        } else {
            return nums[r] + (k - r_missing_cnt);
        }
    }
};
