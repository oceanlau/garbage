class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == nums[mid - 1]) {
                if ((r - mid) % 2 == 1) {
                    l = mid + 1;
                } else {
                    r = mid - 2;
                }
            } else if (nums[mid] == nums[mid + 1]) {
                if ((mid - l) % 2 == 1) {
                    r = mid - 1;
                } else {
                    l = mid + 2;
                }
            } else {
                return nums[mid];
            }
        }
        // r - l is always odd, so if r - l <= 1, r == l
        return nums[r];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // always find in odd length half
        int l = 0;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == nums[mid - 1]) {
                if ((r - mid) % 2 == 0) {
                    r = mid - 2;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] == nums[mid + 1]) {
                if ((r - mid - 1) % 2 == 0) {
                    r = mid - 1;
                } else {
                    l = mid + 2;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[l];
    }
};
