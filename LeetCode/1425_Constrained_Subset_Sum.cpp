class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp (nums.size(), INT_MIN); // max subset sum from 0 - i (including nums[i])
        deque<int> max_dp_locs; //keeps dp locations in a non-inc deque. optimize O(nk) -> O(n)
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i ++) {
            while (!max_dp_locs.empty() && max_dp_locs.front() < i - k) {
                max_dp_locs.pop_front();
            }
            int max_dp_among_prev_k = max_dp_locs.empty() ? 0 : dp[max_dp_locs.front()];
            dp[i] = max(max_dp_among_prev_k, 0) + nums[i];
            ans = max(ans, dp[i]);
            while (!max_dp_locs.empty() && dp[i] > dp[max_dp_locs.back()]) {
                max_dp_locs.pop_back();
            }
            max_dp_locs.push_back(i);
        }
        return ans;
    }
};

//TLE
class Solution {
private:
    vector<int> dp;
    int get_dp(vector<int>& nums, int k, int l) {
        if (l >= nums.size()) {
            return 0;
        }
        if (dp[l] > INT_MIN) {
            return dp[l];
        }
        int max_val = INT_MIN;
        for (int del_cnt = 0; del_cnt < k; del_cnt ++) {
            if (l + del_cnt >= nums.size()) {
                break;
            }
            max_val = max(max_val, nums[l + del_cnt]);
            max_val = max(max_val, nums[l + del_cnt] + get_dp(nums, k, l + del_cnt + 1));
        }
        dp[l] = max_val;
        return max_val;
    }
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        dp = vector<int> (nums.size(), INT_MIN); // max subset sum starting from i ( = (delete 0 - k characters from i then add) the number at (i + deleted count) + max subset sum starting from (i + deleted count + 1))
        int max_val = INT_MIN;
        // since we cannot delete from start, we have to manualy delete them and find max val
        for (int i = 0; i < nums.size(); i++) {
            max_val = max(max_val, get_dp(nums, k, i));
        }
        return max_val;
    }
};

//TLE

class Solution {
private:
    vector<int> dp;
    int get_dp(vector<int>& nums, int k, int l) {
        int r = nums.size() - 1;
        if (l > r) {
            return 0;
        }
        if (dp[l] > INT_MIN) {
            return dp[l];
        }
        int max_val = INT_MIN;
        //assuming there is digits left from i, cannot delete from start
        int prev = 0;
        for (int i = l; i <= r; i++) {
            if (i > l) {
                prev += nums[i - 1];
                if (prev > max_val) {
                    max_val = prev;
                }
            }
            for (int del_cnt = 0; del_cnt < k; del_cnt ++) {
                if (i + del_cnt > r) {
                    break;
                }
                if (prev + nums[i + del_cnt] > max_val) {
                    max_val = prev + nums[i + del_cnt];
                }
                if (prev + nums[i + del_cnt] + get_dp(nums, k, i + del_cnt + 1) > max_val) {
                    max_val = prev + nums[i + del_cnt] + get_dp(nums, k, i + del_cnt + 1);
                }
            }
        }
        dp[l] = max_val;
        return max_val;
    }
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        dp = vector<int> (nums.size(), INT_MIN); // max subset sum starting from i, assuming there is digits left from i (important assumption to bring dp from 2d to 1d)
        int max_val = INT_MIN;
        // since we cannot delete from start, we have to manualy delete them and find max val
        for (int i = 0; i < nums.size(); i++) {
            max_val = max(max_val, get_dp(nums, k, i));
        }
        return max_val;
    }
};
