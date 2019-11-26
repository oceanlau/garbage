class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //https://stackoverflow.com/questions/34701662/vector-size-1-when-size-is-0-in-c
        //so 0 < 0 - 1 is true in size_t
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (i % 2 == 0) {
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i+1]);
                }
            } else if (nums[i] < nums[i + 1]) {
                 swap(nums[i], nums[i+1]);
            }
        }
    }
};
