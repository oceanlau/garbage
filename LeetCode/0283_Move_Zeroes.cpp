class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (zero_idx == -1) {
                    zero_idx = i;
                }
            } else {
                if (zero_idx != -1) {
                    swap(nums[i], nums[zero_idx++]);
                }
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos_0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[pos_0++]);
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Two pointers. Zero element, and first non-element
        int i = 0;
        int j = 0;
        while (i < nums.size() && j < nums.size()) {
            while (i < nums.size() && nums[i] != 0) {
                i ++;
            }
            if (j <= i) {
                j = i + 1;
            }
            while (j < nums.size() && nums[j] == 0) {
                j ++;
            }
            if (i < nums.size() && j < nums.size()) {
                swap(nums[i], nums[j]);
                i ++;
                j ++;
            } else {
                break;
            }
        }
    }
};
