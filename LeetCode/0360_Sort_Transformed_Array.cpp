class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.size() == 0) {
            return {};
        }
        // a >= 0, ends of nums holds largest value
        // a < 0, ends of nums holds smallest value
        int i = 0;
        int j = nums.size() - 1;
        vector<int> res;
        if (a >= 0) {
            while (i <= j) {
                int l = a * nums[i] * nums[i] + b * nums[i] + c;
                int r = a * nums[j] * nums[j] + b * nums[j] + c;
                if (l >= r) {
                    res.push_back(l);
                    i++;
                } else {
                    res.push_back(r);
                    j--;
                }
            }
            reverse(res.begin(), res.end());
        } else {
            while (i <= j) {
                int l = a * nums[i] * nums[i] + b * nums[i] + c;
                int r = a * nums[j] * nums[j] + b * nums[j] + c;
                if (l <= r) {
                    res.push_back(l);
                    i++;
                } else {
                    res.push_back(r);
                    j--;
                }
            }
        }
        return res;
    }
};
