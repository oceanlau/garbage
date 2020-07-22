class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) {
            return 0;
        }
        char last_c = chars[0];
        int last_cnt = 1;
        int write_pos = 0;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == last_c) {
                last_cnt ++;
            } else {
                chars[write_pos++] = last_c;
                last_c = chars[i];
                if (last_cnt > 1) {
                    string count = to_string(last_cnt);
                    for (const char cnt : count) {
                        chars[write_pos++] = cnt;
                    }
                }
                last_cnt = 1;
            }
        }
        chars[write_pos++] = last_c;
        if (last_cnt > 1) {
            string count = to_string(last_cnt);
            for (const char cnt : count) {
                chars[write_pos++] = cnt;
            }
        }
        return write_pos;
    }
};

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() < 2) {
            return chars.size();
        }
        int count = 1;
        char c = chars[0];
        int j = 0;
        // <= edge case
        for (int i = 1; i <= chars.size(); i++) {
            // <= edge case
            if (i < chars.size() && chars[i] == c) {
                count ++;
            } else {
                chars[j++] = c;
                if (count != 1) {
                    string count_str = to_string(count);
                    for (int k = 0; k < count_str.length(); k ++) {
                        chars[j++] = count_str[k];
                    }
                }
                // <= edge case
                if (i < chars.size()) {
                    count = 1;
                    c = chars[i];
                }
            }
        }
        return j;
    }
};
