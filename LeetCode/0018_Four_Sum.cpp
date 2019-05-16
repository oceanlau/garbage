class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for(auto a = nums.begin(); a < nums.end() - 3; a ++) {
            if (a > nums.begin() && *a == *(a-1)) {
                continue;
            }
            for (auto b = a + 1; b < nums.end() - 2; b ++) {
                if (b > a + 1 && *b == *(b-1)) {
                    continue;
                }
                auto c = b + 1;
                auto d = nums.end() - 1;
                while (d > c) {
                    int sum = *a + *b + *c + *d;
                
                    if (sum > target) {
                        while (d > c && *d == *--d) {}
                    } else if (sum < target) {
                        while (d > c && *c == *++c) {}
                    } else {
                        res.push_back(vector<int> {*a, *b, *c, *d});
                        while (d > c && *d == *--d) {}
                        while (d > c && *c == *++c) {}
                    }
                }
            }
        }
        return res;
    }
};
