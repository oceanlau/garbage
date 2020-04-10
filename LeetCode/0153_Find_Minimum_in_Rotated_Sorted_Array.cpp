class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int pivot = nums[r];
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < pivot) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return min(nums[l], nums[r]);
    }
};

class Solution {
private:
    int _find(vector<int>& nums, int i, int j, int right) {
        if (i == j) {
            return nums[i];
        }
        int mid = i + (j - i) / 2;
        if (nums[mid] > right) {
            i = mid + 1;
        } else {
            j = mid;
        }
        return _find(nums, i, j, right);
    }
public:
    int findMin(vector<int>& nums) {
        int size_nums = nums.size();
        return _find(nums, 0, size_nums-1, nums[size_nums-1]);
    }
};
