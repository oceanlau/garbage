//O(nlogn) O(n) 90% 98%
class Solution {
private:
    int _bin_search(vector<int>& dp, int target, int i, int j) {
        while (i + 1 < j) {
            int mid = i + (j - i) / 2;
            if (dp[mid] == target) {
                return mid;
            } else if (dp[mid] > target) {
                if (dp[mid - 1] < target) {
                    return mid;
                } else {
                    j = mid;
                }
            } else {
                i = mid;
            }
        }
        if (dp[i] >= target) {
            return i;
        } else if (dp[j] >= target) {
            return j;
        } else {
            return j + 1;
        }
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        // Some edge cases to consider
        if (nums.size() <= 1) {
            return nums.size();
        }
        //smallest possible ending num in all LIS with length i
        // Some edge cases to consider
        vector<int> dp {nums[0]};
        // Some edge cases to consider
        for (int j = 1; j < nums.size(); j ++) {
            int i = _bin_search(dp, nums[j], 0, dp.size() - 1);
            if (i >= dp.size()) {
                dp.push_back(nums[j]);
            } else {
                dp[i] = nums[j];
            }
        }
        return dp.size();
    }
};

//O(n^2) O(n) 15% 51%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_len = 0;
        int size_nums = nums.size();
        // watch the edge case!
        if (size_nums != 0) {
            max_len = 1;
        }
        //LIS ending at i
        vector<int> dp(size_nums, 1);
        for (int i = 0; i < size_nums; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_len = max(max_len, dp[i]);
                }
            }
        }
        return max_len;
    }
};

//Wrong thinking
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> former;
        unordered_map<int, int> former_val_to_len;//dp
        int max_len = 0;
        int cur_len = 0;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = former.upper_bound(nums[i]);
            if (iter == former.begin()) {
                cur_len = 1;
            } else {
                iter--;
                cur_len = former_val_to_len[*iter] + 1;
            }
            //Wrong thinking! Did not update others!
            if (cur_len > former_val_to_len[nums[i]]) {
                former_val_to_len[nums[i]] = cur_len;
            }
            if (cur_len > max_len) {
                max_len = cur_len;
            }
            former.insert(nums[i]);
        }
        return max_len;
    }
};

// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        int nums_size = nums.size();
        if (nums_size < 2) {
            return nums_size;
        }
        for (const int num : nums) {
            int i = 0;
            int j = tails.size()-1;
            if (j < 0) {
                tails.push_back(num);
                continue;
            }
            while (i + 1 < j) {
                int m = i + (j - i) / 2;
                if (num > tails[m]) {
                    i = m;
                } else {
                    j = m;
                }
            }
            if (num <= tails[i]) {
                tails[i] = num;
            } else if (num <= tails[j]) {
                tails[j] = num;
            } else {
                tails.push_back(num);
            }
        }
        return tails.size();
    }
};

// O(n^2). 15%, 59%. Watch Edge cases!
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_size = nums.size();
        // Edge case: 0 chars
        if (nums_size == 0) {
            return 0;
        }
        // LIS up till i, including char at i
        vector<int> dp(nums_size, 1);
        // Edge case: 1 chars
        int max_len = 1;
        // Edge case: At least 2 chars
        for (int i = 1; i < nums_size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    // This time, we don't use the last dp result.
                    max_len = max(max_len, dp[i]);
                }
            }
        }
        return max_len;
    }
};
