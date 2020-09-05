class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                }
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] > nums[r]) {
            return l;
        }
        return r;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid - 1]) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                } else {
                    l = mid;
                }
            } else {
                r = mid - 1;
            }
        }
        if ((l == nums.size() - 1 || nums[l] > nums[l + 1]) && (l == 0 || nums[l] > nums[l - 1])) {
            return l;
        }
        return r;
    }
};
