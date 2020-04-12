class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int sum = 0;
        int minlen = nums.size() + 1;
        while (r < nums.size()) {
            sum += nums[r];
            if (sum >= s) {
                while (l <= r) {
                    if (sum - nums[l] >= s) {
                        sum -= nums[l];
                        l++;
                    } else {
                        break;
                    }
                }
                minlen = min(minlen, r - l + 1);
            }
            r ++;
        }
        return (minlen == nums.size() + 1) ? 0 : minlen;
    }
};
