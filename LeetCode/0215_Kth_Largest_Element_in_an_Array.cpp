class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        int pivot_val = nums[r];
        int right_part_start = l;
        for (int i = l; i < r; i++) {
            if (nums[i] >= pivot_val) {
                swap(nums[right_part_start], nums[i]);
                right_part_start ++;
            }
        }
        swap(nums[right_part_start], nums[r]);
        return right_part_start;
    }
    int findKth(vector<int>& nums, int l, int r, int k) {
        int pivot_idx = partition(nums, l, r);
        if (pivot_idx == k - 1) {
            return nums[pivot_idx];
        }
        if (pivot_idx > k - 1) {
            return findKth(nums, l, pivot_idx - 1, k);
        }
        //return findKth(nums, pivot_idx + 1, r, k - pivot_idx - 1);
        return findKth(nums, pivot_idx + 1, r, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size() - 1, k);
    }
};
