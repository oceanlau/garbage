// 60% 95%
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }
        //binary search with 4 scene
        //let last one be pivot
        int pivot = nums[nums.size() - 1];
        if (target == pivot) {
            return true;
        }
        int i = 0;
        int j = nums.size() - 1;
        if (i + 1 < j) {
            //Avoid left == right == mid case. Break left == right equality
            j --;
            while (i + 1 < j && nums[j] == nums[j+1]) {
                j --;
            }
            pivot = nums[j];
            if (target == pivot) {
                return true;
            }
            while (i + 1 < j) {
                int m = i + (j - i) / 2;
                if (nums[m] == target) {
                    return true;
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
        }
        
        if (nums[i] == target) {
            return true;
        } else if (nums[j] == target) {
            return true;
        } else {
            return false;
        }
    }
};

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
