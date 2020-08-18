class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0;
        for (int cnt = 0; cnt < nums.size();) {
            int j = i;
            int last = nums[j];
            do {
                j = (j + k) % (int) nums.size();
                int cur = nums[j];
                nums[j] = last;
                last = cur;
                cnt ++;
            } while (j != i);
            i ++;
        }
    }
};
