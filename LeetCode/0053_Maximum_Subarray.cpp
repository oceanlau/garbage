class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return INT_MIN;
        }
        //careful 不能初始化为0！
        int res = INT_MIN;
        //careful here!从0开始，不然会忽略从第0个元素开始情况
        int current_min_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur_sum = nums[i];
            if (i > 0) {
                nums[i] += nums[i-1];
            }
            
            if (nums[i] < current_min_sum) {
                current_min_sum = nums[i];
            } else {
                cur_sum = nums[i] - current_min_sum;
            }
            if (cur_sum > res) {
                res = cur_sum;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max_sum = nums[0];
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            current_sum += nums[i];          
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
            //trick!!
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        return max_sum;
    }
};
