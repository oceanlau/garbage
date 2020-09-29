class Solution {
public:
    int lengthLongestPath(string input) {
        string part;
        stringstream input_ss (input);
        vector<int> part_lens_presum;
        int max_len = 0;
        while (getline(input_ss, part,  '\n')) {
            int part_nth = 0;
            for (int i = 0; i < part.length(); i++) {
                if (part[i] == '\t') {
                    part_nth ++;
                } else {
                    break;
                }
            }
            int part_len = part.length() - part_nth;
            if (part_lens_presum.empty()) {
                part_lens_presum.push_back(part_len);
            } else if (part_lens_presum.size() < part_nth + 1) {
                part_lens_presum.push_back(part_lens_presum.back() + part_len);
            } else if (part_nth - 1 >= 0){
                part_lens_presum[part_nth] = part_lens_presum[part_nth - 1] + part_len;
            } else {
                part_lens_presum[part_nth] = part_len;
            }
            if (part.find('.') != string::npos) {
                max_len = max(max_len, part_lens_presum[part_nth] + part_nth);
            }
        }
        return max_len;
    }
};

class Solution {
public:
    int lengthLongestPath(string input) {
        // 顺序读
        // [lv1 len, lv2 len, file len] cur len
        // [lv1 len, lv2-2 len, lv3-2 len, file len] cur len
        // 不对 用presum
        vector<int> lens(1,0);
        int max_len = 0;
        int dir_lvl = 0;
        bool is_file = false;
        int name_len = 0;
        //dont forget the last invisible \n!
        for (int i = 0; i <= input.length(); i++) {
            char c;
            if (i < input.length()) {
                c = input[i];
            }
            if (i == input.length() || c == '\n') {
                lens[dir_lvl] = name_len;
                lens[dir_lvl] += dir_lvl > 0 ? lens[dir_lvl - 1] + 1 : 0;
                if (is_file) {
                    max_len = max(max_len, lens[dir_lvl]);
                }
                dir_lvl = 0;
                is_file = false;
                name_len = 0;
            } else if (c == '\t') {
                dir_lvl ++;
                if (dir_lvl >= lens.size()) {
                    lens.push_back(0);
                }
            } else {
                if (c == '.') {
                    is_file = true;
                }
                name_len ++;
            }
        }
        return max_len;
    }
};

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
