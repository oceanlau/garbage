class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 1;
        int j = 1;
        int last_digit = nums[0];
        while (j < nums.size()) {
            if (nums[j] != last_digit) {
                last_digit = nums[j];
                swap(nums[i++], nums[j]);
            }
            j ++;
        }
        return i;
    }
};

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
