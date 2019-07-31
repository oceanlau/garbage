//60% 60%
class Solution {
private:
    bool _binary_search_no_less_than(vector<int>& nums, int start, int end, int target, int bottom) {
        int mid_pos = (start + end) / 2;
        int mid = nums[mid_pos];
        if (mid > target || mid < bottom) {
            if (mid_pos == start) {
                return false;
            }
            return _binary_search_no_less_than(nums, start, mid_pos - 1, target, bottom);
        } else if (mid < target) {
            if (mid_pos == end) {
                return false;
            }
            return _binary_search_no_less_than(nums, mid_pos + 1, end, target, bottom);
        }
        return true;
    }
    
    bool _binary_search_no_more_than(vector<int>& nums, int start, int end, int target, int top) {
        int mid_pos = (start + end) / 2;
        int mid = nums[mid_pos];
        if (mid < target || mid > top) {
            if (mid_pos == end) {
                return false;
            }
            return _binary_search_no_more_than(nums, mid_pos + 1, end, target, top);
        } else if (mid > target) {
            if (mid_pos == start) {
                return false;
            }
            return _binary_search_no_more_than(nums, start, mid_pos - 1, target, top);
        }
        return true;
    }
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }
        int start_pos = 0;
        int right_pos = nums.size() - 1;
        int left = nums[start_pos];
        int right = nums[right_pos];
        if (target == left || target == right) {
            return true;
        } else if (right_pos > 0) {
            if (target > left) {
                while (right_pos - 1 > 0 && nums[right_pos - 1] == nums[right_pos]) {
                    right_pos --;
                }
                return _binary_search_no_less_than(nums, 0, right_pos - 1, target, left);
            } else if (target < right) {
                while (start_pos < right_pos && nums[start_pos + 1] == nums[start_pos]) {
                    start_pos ++;
                }
                return _binary_search_no_more_than(nums, start_pos, right_pos, target, right);
            }
        }
        return false;
    }
};
