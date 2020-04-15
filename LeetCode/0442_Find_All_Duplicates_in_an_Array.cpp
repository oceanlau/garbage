
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size();) {
            int cur = nums[i];
            if (cur == 0 || cur - 1 == i) {
                i ++;
                continue;
            }
            if (nums[cur - 1] == nums[i]) {
                res.push_back(nums[i]);
                nums[cur - 1] = 0;
                nums[i] = 0;
                i ++;
            } else {
                swap(nums[cur - 1], nums[i]);
            }
        }
        return res;
    }
};

// oppo of what they want...
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            int cur = nums[i];
            //careful!
            if (cur == 0 || cur-1 == i) {
                i ++;
                continue;
            }
            if (nums[cur - 1] == cur) {
                nums[cur - 1] = 0;
                nums[i] = 0;
                i++;
            } else {
                swap(nums[cur - 1], nums[i]);
            }
        }
        vector<int> ans;
        for (const int val : nums) {
            if (val != 0) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
