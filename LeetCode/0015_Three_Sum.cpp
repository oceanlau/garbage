class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        std::sort(nums.begin(), nums.end());
        auto i = nums.begin();
        while (i < nums.end() - 2) {
            if (i > nums.begin() && *i == *(i-1)) {
                i ++;
                continue;
            }
            auto j = i + 1;
            auto k = nums.end() - 1;
            while (k > j) {
                if (*i + *j + *k == 0) {
                    res.push_back(vector<int> {*i, *j, *k});
                    while (*k == *--k && k > j){}
                    while (*j == *++j && k > j){}
                } else if (*i + *j + *k > 0) {
                    while (*k == *--k && k > j){}
                } else if (*i + *j + *k < 0) {
                    while (*j == *++j && k > j){}
                }
            }
            i ++;
        }
        return res;
    }
};
