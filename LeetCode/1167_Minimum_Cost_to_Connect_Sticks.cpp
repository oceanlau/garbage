class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minheap(sticks.begin(), sticks.end());
        int sum = 0;
        //careful ! >1
        while(minheap.size() > 1) {
            int cur = 0;
            cur += minheap.top();
            minheap.pop();
            cur += minheap.top();
            minheap.pop();
            //careful! push back
            minheap.push(cur);
            sum += cur;
        }
        return sum;
    }
};

//wrong thinking, not continous!
class Solution {
private:
    int _get_dp(vector<vector<int>>& dp, vector<int>& presum, int l, int r) {
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        if (l == r){
            dp[l][r] = 0;
        } else {
            int min_lr = INT_MAX;
            for(int t = l; t < r; t++) {
                int left = _get_dp(dp, presum, l, t);
                int right = _get_dp(dp, presum, t+1, r);
                min_lr = min(min_lr, left+right);
            }
            dp[l][r] = min_lr + presum[r];
            if (l > 0) {
                dp[l][r] -= presum[l-1];
            }
        }
        return dp[l][r];
    }
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 0){
            return 0;
        }
        //dp[l][r] = min(dp[l][t] + dp[t+1][r]) + sum(l-r)
        vector<vector<int>> dp(sticks.size(), vector<int>(sticks.size(), -1));
        vector<int> presum(sticks.size(), 0);
        presum[0] = sticks[0];
        for(int i = 1; i < sticks.size(); i++) {
            presum[i] = sticks[i] + presum[i-1];
        }
        return _get_dp(dp, presum, 0, sticks.size() - 1);
        
    }
};
