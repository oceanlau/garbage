// 67.95% 30.77% Why slow?
class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 0;
        int ratings_size = ratings.size();
        if (ratings_size == 0) {
            return result;
        }
        vector<int> nums(ratings_size, 1);
        // Make sure nums of i is larger than its left neighbor if its rating is higher
        for (int i = 1; i < ratings_size; i++) {
            if (ratings[i] > ratings[i-1]) {
                nums[i] = nums[i-1] + 1;
            }
        }
        result += nums[ratings_size - 1];
        // Make sure nums of i is larger than its right neighbor if its rating is higher
        for (int i = ratings_size - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                nums[i] = max(nums[i], nums[i+1] + 1);
            }
            result += nums[i];
        } 
        return result;
    }
};
