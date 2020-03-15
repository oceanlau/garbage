class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        int left_of_1 = 0;
        int right_of_1 = nums.size() - 1;
        for (int i = 0; i <= right_of_1;) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left_of_1]);
                left_of_1 ++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right_of_1]);
                right_of_1 --;
            } else {
                i++;
            }
        }
    }
};

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
