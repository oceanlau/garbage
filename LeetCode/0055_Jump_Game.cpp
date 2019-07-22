class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int max_end = 0;
        while (end < nums.size()) {
            for (int i = start; i <= end; i++) {
                if (nums[i] + i > max_end) {
                    max_end = nums[i] + i;
                }
            }
            if (max_end >= nums.size() - 1) {
                return true;
            }
            if (max_end == end) {
                return false;
            }
            start = end + 1;
            end = max_end;
        }
        return true;
    }
};
