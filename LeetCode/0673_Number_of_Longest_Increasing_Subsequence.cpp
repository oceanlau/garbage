//Wrong thinking
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        set<int> former;
        unordered_map<int, int> former_val_to_len;//dp
        int max_len = 0;
        int max_cnt = 0;
        int cur_len = 0;
        for(int i = 0; i < nums.size(); i++) {
            //wrong thinking. many results skipped. consider [1,3,5,4,7] test case
            auto iter = former.upper_bound(nums[i]);
            if (iter == former.begin()) {
                cur_len = 1;
            } else {
                iter--;
                cur_len = former_val_to_len[*iter] + 1;
            }
            if (cur_len > former_val_to_len[nums[i]]) {
                former_val_to_len[nums[i]] = cur_len;
            }
            if (cur_len > max_len) {
                max_len = cur_len;
                max_cnt = 1;
            } else if (cur_len == max_len) {
                max_cnt ++;
            }
            former.insert(nums[i]);
        }
        return max_cnt;
    }
};
