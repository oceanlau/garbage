class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        int total = 0;
        int max_sub = INT_MIN;
        int min_sub = INT_MAX;
        
        int max_sub_pre = 0;
        int min_sub_pre = 0;
        for (const int a : A) {
            max_sub_pre = max(max_sub_pre, 0) + a;
            max_sub = max(max_sub_pre, max_sub);
            min_sub_pre = min(min_sub_pre, 0) + a;
            min_sub = min(min_sub_pre, min_sub);
            total += a;
        }
        
        //careful! cant remove every element. if total is really min_sub, might as well use max_sub, must be 0
        if (total != min_sub) {
            return max(max_sub, total - min_sub);
        } else {
            return max_sub;
        }
    }
};
