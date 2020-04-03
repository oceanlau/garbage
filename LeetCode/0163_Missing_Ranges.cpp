class Solution {
private:
    string _gen_range(int l, int r) {
        if (l == r) {
            return to_string(l);
        }
        return to_string(l) + "->" + to_string(r);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) {
            return {_gen_range(lower, upper)};
        }
        vector<string> ranges;
        if (nums[0] > lower) {
            ranges.push_back(_gen_range(lower, nums[0] - 1));
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1] && nums[i] - 1 != nums[i-1]) {
                ranges.push_back(_gen_range(nums[i-1] + 1, nums[i] - 1));
            }
        }
        if (upper > nums[nums.size() - 1]) {
            ranges.push_back(_gen_range(nums[nums.size() - 1] + 1, upper));
        }
        return ranges;
    }
};
