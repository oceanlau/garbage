//99% 11%
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

//wrong
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        //smallest ending num among all LIS with length i
        vector<int> dp;
        dp.push_back(nums[0]);
        //wrong thiking  [1,2,4,3,5,4,7,2]
        vector<int> dp_cnt;
        dp_cnt.push_back(1);
        // for each num, bin search on dp, put num in suitable pos of dp.
        // if pos is at the end of dp,  we update max_cnt (=1 or ++)
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
            if (dp[l] >= nums[i]) {
                dp[l] = nums[i];
                dp_cnt[l] ++;
            } else if (dp[r] >= nums[i]) {
                dp[r] = nums[i];
                dp_cnt[r] ++;
            } else {
                dp.push_back(nums[i]);
                dp_cnt.push_back(1);
            }
        }
        int max_cnt = 1;
        for (int i = 0; i < dp_cnt.size(); i++) {
            max_cnt *= dp_cnt[i];
        }
        return max_cnt;
    }
};

//Wrong thinking
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        set<int> former;
        unordered_map<int, int> former_val_to_len;//dp
        int max_len = 0;
        int max_cnt = 0;
        int cur_len = 0;
        for(int i = 0; i < nums.size(); i++) {
            //wrong thinking. many results skipped. consider [1,3,5,4,7] test case
            auto iter = former.upper_bound(nums[i]);
            if (iter == former.begin()) {
                cur_len = 1;
            } else {
                iter--;
                cur_len = former_val_to_len[*iter] + 1;
            }
            if (cur_len > former_val_to_len[nums[i]]) {
                former_val_to_len[nums[i]] = cur_len;
            }
            if (cur_len > max_len) {
                max_len = cur_len;
                max_cnt = 1;
            } else if (cur_len == max_len) {
                max_cnt ++;
            }
            former.insert(nums[i]);
        }
        return max_cnt;
    }
};
