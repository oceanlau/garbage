class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (const int n : nums) {
            single ^= n;
        }
        return single;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> unique_nums;
        for (const int num : nums) {
            if (unique_nums.count(num)) {
                unique_nums.erase(num);
            } else {
                unique_nums.insert(num);
            }
        }
        return *unique_nums.begin();
    }
};
