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
