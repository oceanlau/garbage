//97% 88% Copied! Early stopping!
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+= nums[i];
        }
        if(sum%2) return false;
        sum /= 2;
        sort(nums.rbegin(),nums.rend());
        return helper(nums, sum, 0);
    }
    bool helper(vector<int>& nums, int sum, int index){
        if(index >= nums.size())
        {
            return false;
        }
        if(sum == nums[index]) return true;
        if(sum < nums[index]) return false;
        return helper(nums,sum-nums[index],index+1) || helper(nums,sum,index+1);
    }
};

//MLE
class Solution {
private:
    bool _bt(vector<int>& nums, int start, int target) {
        if (start >= nums.size() || target <= 0) {
            return target == 0;
        }
        for (; start < nums.size(); start++) {
            if (_bt(nums, start + 1, target - nums[start])) {
                return true;
            }
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        return _bt(nums, 0, sum);
    }
};
