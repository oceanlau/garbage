class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        if (nums.size() == 1) {
            return {to_string(nums[0])};
        }
        vector<string> ans;
        for (int i = 0; i < nums.size();) {
            int start = nums[i];
            string range = to_string(nums[i]);
            i++;
            while (i < nums.size() && nums[i] == nums[i-1] + 1) {
                i++;
            }
            if (nums[i - 1] > start) {
                range += "->" + to_string(nums[i - 1]);
            }
            ans.push_back(range);
        }
        return ans;
    }
};
