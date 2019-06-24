class Solution {
private:
    int _find(const vector<int>& nums, int pivot, int left, int right, int target) {
        if (left == right || right == left + 1) {
            if (nums[left] == target) {
                return left;
            } else if (nums[right] == target) {
                return right;
            }
            return -1;
        }
        int center = (left + right) / 2;
        if (nums[center] == target) {
            return center;
        } else if (nums[center] > pivot) {
            if (target < pivot || target > nums[center]) {
                return _find(nums, pivot, center, right, target);
            }
            return _find(nums, pivot, left, center, target);
        } else {
            if (target >= pivot || target < nums[center]) {
                return _find(nums, pivot, left, center, target);
            }
            return _find(nums, pivot, center, right, target);
        }
    }
    
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int pivot = nums[0];
        return _find(nums, pivot, 0, nums.size() - 1, target);
    }
};
