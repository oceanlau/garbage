class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return false;
        }
        unordered_set<int> remainders;
        // delay the insert of remainder. To make sure remainders.count only the element 2 distance in the past
        int remainder = 0;
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            int new_remainder = (k == 0) ? cur_sum : cur_sum % k;
            if (remainders.count(new_remainder)) {
                return true;
            }
            remainders.insert(remainder);
            remainder = new_remainder;
        }
        return false;
    }
};
// wrong thinking, consider [1,2,12],6
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return false;
        }
        unordered_set<int> remainders;
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            int remainder = (k == 0) ? cur_sum : cur_sum % k;
            if (i > 0) {
                if (remainder == 0) {
                    return true;
                }
                //*,0 got same remainder twice. But it's pointless!
                if (!(nums[i] == 0 && nums[i-1] != 0) && remainders.count(remainder)) {
                    return true;
                }
            }
            remainders.insert(remainder);
        }
        return false;
    }
};
