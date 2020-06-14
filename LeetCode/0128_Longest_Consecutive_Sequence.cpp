class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (auto it = s.begin(); it != s.end(); it ++) {
            int n  = *it;
            if (s.count(n - 1)) {
                continue;
            }
            int len = 1;
            while (s.count(n + 1)) {
                n = n + 1;
                len ++;
            }
            longest = max(longest, len);
        }
        return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (int n : nums) {
            if (!s.count(n - 1)) {
                int streak = 1;
                while (s.count(n + 1)) {
                    streak ++;
                    n ++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
