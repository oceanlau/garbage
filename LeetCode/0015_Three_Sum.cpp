class Solution {
public:
    //sort + two pointer
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = 0;
            int third = 0;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    results.push_back({nums[i], nums[j++], nums[k--]});
                    while (j <= k && nums[j] == nums[j-1]) {
                        j ++;
                    }
                    while (k >= j && nums[k] == nums[k+1]) {
                        k --;
                    }
                } else if (sum > 0) {
                    k --;
                } else {
                    j ++;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
        }
        return results;
    }
};

//wrong thinking. Cannot avoid dupes
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (const int num : nums) {
            counter[num] ++;
        }
        vector<vector<int>> results;
        for (auto it1 = counter.begin(); it1 != counter.end(); it1++) {
            int first = it1->first;
            int second = 0;
            int third = 0;
            it1->second --;
            for (auto it2 = it1; it2 != counter.end(); it2++) {
                if (it2->second > 0) {
                    second = it2->first;
                    it2->second --;
                    third = 0 - first - second;
                    if (counter.count(third) && counter[third] > 0) {
                        results.push_back({first, second, third});
                    }
                    it2->second ++;
                }
            }
        }
        return results;
    }
};

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
                    // No Need
                    while (*k == *--k && k > j){}
                } else if (*i + *j + *k < 0) {
                    // No Need
                    while (*j == *++j && k > j){}
                }
            }
            i ++;
        }
        return res;
    }
};
