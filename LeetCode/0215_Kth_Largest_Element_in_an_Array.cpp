class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        int pivot_idx = l + (rand() % (r - l));
        swap(nums[r], nums[pivot_idx]);
        int left_idx = l;
        for (int i = l; i < r; i++) {
            if (nums[i] >= nums[r]) {
                swap(nums[left_idx++], nums[i]);
            }
        }
        swap(nums[left_idx], nums[r]);
        return left_idx;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int nth = partition(nums, l, r);
            if (nth == k - 1) {
                return nums[nth];
            } else if (nth > k - 1) {
                r = nth - 1;
            } else {
                l = nth + 1;
            }
        }
        return nums[l];
    }
};

class Solution {
private:
    int partition(vector<int>& nums, int i, int j) {
        int pivot = j;
        for (int idx = i; idx < pivot; idx ++) {
            if (nums[idx] <= nums[pivot]) {
                swap(nums[i++], nums[idx]);
            }
        }
        swap(nums[i], nums[pivot]);
        return i;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i = 0;
        int j = nums.size() - 1;
        while (i != j) {
            int nth = partition(nums, i, j);
            if (nums.size() - nth == k) {
                return nums[nth];
            } else if (nums.size() - nth > k) {
                i = nth + 1;
            } else {
                j = nth - 1;
            }
        }
        return nums[i];
    }
};

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
