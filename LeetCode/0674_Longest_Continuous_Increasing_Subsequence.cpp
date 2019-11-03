//85% 83%
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int largest = 0;
        int start = 0;
        int size_nums = nums.size();
        for(int i = 1; i < size_nums; i++) {
            if (nums[i] <= nums[i-1]) {
                largest = max(largest, i - start);
                start = i;
            }
        }
        // compute largest every step regardless of i i-1 comparison result, could avoid this final patch
        return max(largest, (size_nums - start));
    }
};
