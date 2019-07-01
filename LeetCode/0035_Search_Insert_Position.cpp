class Solution {
private:
    int _find(const vector<int>& nums, int left, int right, int target) {
        if (left == right || left + 1 == right) {
            if (nums[left] >= target) {
                return left;
            } else if (nums[right] >= target) {
                return right;
            } else if (nums[right] < target) {
                return right + 1;
            }
            return -1;
        }
        int center = (left + right) / 2;
        if (nums[center] == target) {
            return center;
        } else if (target < nums[center]) {
            return _find(nums, left, center, target);
        } else {
            return _find(nums, center, right, target);
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        return _find(nums, 0, nums.size() - 1, target);
    }
};
