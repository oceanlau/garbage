class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n <= 0) {
            return;
        }
        int max_right = nums[n];
        n --;
        while (n >= 0) {
            if (nums[n] < max_right) {
                sort(nums.begin() + n + 1, nums.end());
                for (auto iter = nums.begin() + n + 1; iter != nums.end(); iter++) {
                    if (*iter > nums[n]) {
                        int tmp = nums[n];
                        nums[n] = *iter;
                        *iter = tmp;
                        break;
                    }
                }
                break;
            } else if (nums[n] > max_right) {
                max_right = nums[n];
            }
            n --;
        }
        if (n == -1) {
            sort(nums.begin(), nums.end());
        }
    }
};
