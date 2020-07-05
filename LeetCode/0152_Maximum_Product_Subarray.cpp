class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int last_max = nums[0];
        int last_min = nums[0];
        int peak = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            if (n > 0) {
                last_max = max(n, last_max * n);
                last_min = min(n, last_min * n);
            } else {
                int tmp_last_max = last_max;
                last_max = max(n, last_min * n);
                last_min = min(n, tmp_last_max * n);
            }
            peak = max(peak, last_max);
        }
        return peak;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } 
        int ans = nums[0];
        int last_max = nums[0];
        int last_min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num >= 0) {
                last_max = max(num, num*last_max);
                last_min = min(num, num*last_min);
            } else {
                int tmp_last_max = last_max;
                last_max = max(num, num*last_min);
                last_min = min(num, num*tmp_last_max);
            }
            if (last_max > ans) {
                ans = last_max;
            }
        }
        return ans;
    }
};
