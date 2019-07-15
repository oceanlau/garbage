class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 == nums[i]) {
                continue;
            }
            while (nums[i] > 0 && nums[i] < nums.size() + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

//not constant space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> positive_ints;
        for (int i = 1; i < nums.size() + 2; i++) {
            positive_ints.insert(positive_ints.end(), i);
        }
        
        for (int i : nums) {
            positive_ints.erase(i);
        }
        
        return *positive_ints.begin();
    }
};
