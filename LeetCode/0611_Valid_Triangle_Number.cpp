class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int ans = 0;
        // weird (int)
        for (int i = 0; i < (int)nums.size() - 2; i ++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] > nums[i]) {
                    ans += k - j;
                    j ++;
                } else {
                    k --;
                }
            }
        }
        return ans;
    }
};
