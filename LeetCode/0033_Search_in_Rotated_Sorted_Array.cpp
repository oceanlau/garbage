// 80% 44%
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        //binary search with 4 scene
        //let last one be pivot
        int pivot = nums[nums.size() - 1];
        if (target == pivot) {
            return nums.size() - 1;
        }
        int i = 0;
        int j = nums.size() - 1;
        while (i + 1 < j) {
            int m = i + (j - i) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target && target > pivot) {
                //larger than target, target larger than pivot, left side
                j = m;
            } else if ((nums[m] > target && target < pivot) || (nums[m] < target && target > pivot)) {
                //larger than target, target smaller than pivot, if larger than pivot, right, if smaller, left
                //smaller than target, target larger than pivot, if larget than pivot, right, if smaller, left
                // since no deuplicate, otherwise?
                if (nums[m] > pivot) {
                    i = m;
                } else {
                    j = m;
                }
            //} else if (ums[m] < target && target < pivot){
            } else {
                //smaller than target, target smaller than pivot, right side
                i = m;
            }
        }
        if (nums[i] == target) {
            return i;
        } else if (nums[j] == target) {
            return j;
        } else {
            return -1;
        }
    }
};

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
