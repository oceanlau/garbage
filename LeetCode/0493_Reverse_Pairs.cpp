class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort_and_count(nums, 0, nums.size() - 1);
    }
    int mergesort_and_count(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int mid = l + (r - l) / 2;
        int cnt = mergesort_and_count(nums, l, mid) + mergesort_and_count(nums, mid + 1, r);
        // For counting
        int i = l;
        int j = mid + 1;
        while (i <= mid) {
            // Counting
            while (j <= r && nums[i] / 2.0 > nums[j]) {
                j ++;
            }
            cnt += j - (mid + 1);
            i ++;
        }
        // Merging
        sort(nums.begin() + l, nums.begin() + r + 1);
        //merge(nums, l, mid, r);
        return cnt;
    }
    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> copied = nums;
        int idx = l;
        int i = l;
        int j = mid + 1;
        while (i <= mid || j <= r) {
            if (i > mid || (j <= r && copied[i] >= copied[j])) {
                nums[idx ++] = copied[j ++];
            } else {
                nums[idx ++] = copied[i ++];
            }
        }
    }
};
