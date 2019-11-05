//O(nlogn) 99% 11%
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        //smallest possible ending num in all LIS with length i
        vector<int> dp {nums[0]};
        //a map of subsequence ending at key to its possible LIS cnt int val
        //the vector index is LIS length i
        vector<unordered_map<int, int>> dp_history;
        dp_history.push_back(unordered_map<int, int> {{nums[0], 1}});
        // for each num, bin search on dp, put num in suitable pos of dp
        // the num would be the map key
        // the val is possble LIS cnt, caculated by summing over the previous map item vals if the key is less than cur num
        for (int i = 1; i < nums.size(); i++) {
            int l = 0;
            int r = dp.size() - 1;
            while (l + 1 < r) {
                int mid = l + (r - l) / 2;
                if (dp[mid] > nums[i]) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            int cur_pos = 0;
            if (dp[l] >= nums[i]) {
                dp[l] = nums[i];
                cur_pos = l;
            } else if (dp[r] >= nums[i]) {
                dp[r] = nums[i];
                cur_pos = r;
            } else {
                dp.push_back(nums[i]);
                cur_pos = dp.size() - 1;
                dp_history.push_back(unordered_map<int, int> {});
            }
            if (cur_pos == 0) {
                dp_history[cur_pos][nums[i]] ++;
            } else {
                int cnt = 0;
                for (auto it = dp_history[cur_pos-1].begin(); it != dp_history[cur_pos-1].end(); it++) {
                    if (it->first < nums[i]) {
                        cnt += it->second;
                    }
                }
                //+=! 4 6 7 7
                dp_history[cur_pos][nums[i]] += cnt;
            }
        }
        int max_cnt = 0;
        for (auto it = dp_history.back().begin(); it != dp_history.back().end(); it++) {
            max_cnt += it->second;
        }
        return max_cnt;
    }
};

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
