class Solution {
private:
    vector<int> original_nums;
    vector<int> current_nums;
public:
    Solution(vector<int>& nums) {
        original_nums = nums;
        current_nums = original_nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        current_nums = original_nums;
        return current_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int left = current_nums.size();
        for (int i = 0; i < current_nums.size(); i++) {
            swap(current_nums[i], current_nums[i + rand() % left]);
            left --;
        }
        return current_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
