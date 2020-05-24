class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int last_seg_len = 0; // containing the mid 0
        int last_0 = -1;
        int max_len = 0;
        for (int i = 0; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] == 0) {
                int len = i - 1 - last_0 + last_seg_len;
                max_len = max(max_len, len);
                last_seg_len = i - last_0;
                last_0 = i;
            }
        }
        return max_len;
    }
};
