class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int read_idx = 0;
        int write_idx = 0;
        while (read_idx < nums.size()) {
            if (read_idx == 0) {
                read_idx ++;
                write_idx ++;
                continue;
            }
            if (nums[read_idx] != nums[read_idx - 1]) {
                nums[write_idx] = nums[read_idx];
                write_idx ++;
            }
            read_idx ++;
        }
        return write_idx;
    }
};
