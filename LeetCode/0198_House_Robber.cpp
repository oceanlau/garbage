class Solution {
public:
    int rob(vector<int>& nums) {
        int dont_rob = 0;
        int rob = 0;
        for (const int num : nums) {
            int prev_rob = rob;
            rob = num + dont_rob;
            dont_rob = max(prev_rob, dont_rob);
        }
        return max(rob, dont_rob);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp_1 = nums[0];
        int dp_2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            int tmp = dp_1;
            dp_1 = max(dp_1, nums[i] + dp_2);
            dp_2 = tmp;
        }
        return dp_1;
    }
};

// wrong understanding. Rob more than 2!
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(make_pair(-nums[i], i));
            if (pq.size() > 3) {
                pq.pop();
            }
        }
        pair<int, int> no1 = pq.top();
        pq.pop();
        pair<int, int> no2 = pq.top();
        pq.pop();
        if (abs(no1.second - no2.second) != 1) {
            return -no1.first-no2.first;
        }
        pair<int, int> no3 = pq.top();
        if (abs(no1.second - no3.second) != 1) {
            return -no1.first-no3.first;
        }
        return -no2.first-no3.first;
    }
};
