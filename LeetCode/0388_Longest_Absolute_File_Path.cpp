class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> len_presums;
        int max_len = 0;
        int lvl= 0;
        bool is_file = false;
        int cur_len = 0;
        for (int i = 0; i <= input.length(); i++) {
            if (i == input.length() || input[i] == '\n') {
                int cur_presum = cur_len + 1;// + 1 for the final /
                if (lvl > 0) {
                    cur_presum += len_presums[lvl - 1];
                }
                if (lvl + 1 > len_presums.size()) {
                    len_presums.push_back(cur_presum);
                } else {
                    len_presums[lvl] = cur_presum;
                }
                if (is_file) {
                    max_len = max(len_presums[lvl], max_len);
                }
                lvl = 0;
                is_file = false;
                cur_len = 0;
            } else if (input[i] == '\t') {
                lvl++;
            } else {
                if (input[i] == '.') {
                    is_file = true;
                }
                cur_len++;
            }
        }
        if (max_len > 0) {
            return max_len - 1; // remove 1 for the final /
        } else {
            return 0;
        }
    }
};
