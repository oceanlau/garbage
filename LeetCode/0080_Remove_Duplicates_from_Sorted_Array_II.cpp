class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int to_replace_pos = 0;
        int last = -1;
        int times = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != last) {
                last = nums[i];
                times = 1;
            } else if (++times > 2) {
                continue;
            }
            if (to_replace_pos != i) {
                swap(nums[to_replace_pos], nums[i]);
            }
            to_replace_pos++;
        }
        return to_replace_pos;
    }
};
