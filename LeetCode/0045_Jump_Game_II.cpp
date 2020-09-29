class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int max_jump = 0;
        int last_max_jump = -1;
        int steps = 0;
        while (max_jump < nums.size() - 1) {
            int new_max_jump = max_jump;
            for (int i = last_max_jump + 1; i <= max_jump; i++) {
                new_max_jump = max(new_max_jump, i + nums[i]);
            }
            last_max_jump = max_jump;
            max_jump = new_max_jump;
            steps ++;
        }
        return steps;
    }
};

// Slow. Only need to greedy find max jump like in jump game I
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        vector<int> dp (nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j ++) {
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
                if (i + j == nums.size() - 1) {
                    return dp[i + j];
                }
            }
        }
        return dp.back();
    }
};

//BFS
class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int end = 1;
        int steps = 0;
        while (end < nums.size()) {
            int max_end = end;
            for (int i = start; i < end; i++) {
                int tmp = i + nums[i];
                if (tmp + 1 > max_end) {
                    max_end = tmp + 1;
                }
            }
            steps++;
            if (max_end >= nums.size()) {
                return steps;
            }
            start = end;
            end = max_end;
        }
        return steps;
    }
};

//reversed, but still O(n^2). Too slow.
class Solution {
private:
    vector<int> _nums;
    //min number of jumps required to get to nth pos
    //vector<int> _dp;
    int _getDp(int pos) {
        int min_pos = pos;
        int distance = 0;
        do {
            pos --;
            distance ++;
            if (_nums[pos] >= distance) {
                min_pos = pos;
            }
        } while (pos > 0);
        if (min_pos == 0) {
            return 1;
        } else {
            return _getDp(min_pos) + 1;
        }
    }
    
public:
    int jump(vector<int>& nums) {
        _nums = nums;
        if (nums.size() <= 1) {
            return 0;
        }
        return _getDp(nums.size() - 1);
    }
};
