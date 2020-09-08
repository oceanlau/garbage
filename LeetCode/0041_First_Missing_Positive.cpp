class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == i + 1 || nums[i] <= 0) {
            } else if (nums[i] > nums.size() || nums[nums[i] - 1] == nums[i]) {
                nums[i] = 0;
            } else {
                swap(nums[i], nums[nums[i] - 1]);
                i --;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums.size()) {
                nums[i] = 0;
            } else if (nums[i] > 0) {
                if (nums[i] != i + 1) {
                    if (nums[nums[i] - 1] == nums[i]) {
                        nums[i] = 0;
                    } else {
                        swap(nums[i], nums[nums[i] - 1]);
                        i--;
                    }
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int runner = 0;
        int max_num = nums.size();
        while (runner < nums.size()) {
            if (nums[runner] > max_num || nums[runner] <= 0) {
                nums[runner] = -1;
            } else if (nums[runner] > 0 && runner + 1 != nums[runner]) {//dont need to swap with itself
                if (nums[nums[runner] - 1] == nums[runner]) { // destination already fulfilled
                    nums[runner] = -1;
                } else {
                    swap(nums[nums[runner] - 1], nums[runner]);
                    continue;
                }
            }
            runner ++;
        }
        int missing_ptr = 0;
        while(missing_ptr < max_num && nums[missing_ptr] != -1) {
            missing_ptr ++;
        }
        return missing_ptr + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 == nums[i]) {
                continue;
            }
            while (nums[i] > 0 && nums[i] < nums.size() + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

//not constant space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> positive_ints;
        for (int i = 1; i < nums.size() + 2; i++) {
            positive_ints.insert(positive_ints.end(), i);
        }
        
        for (int i : nums) {
            positive_ints.erase(i);
        }
        
        return *positive_ints.begin();
    }
};
