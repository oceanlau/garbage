class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin_pos = 0;
        unordered_map<char, int> pos;
        int longest = 0;
        for (int i = 0; i < s.length(); i++) {
            if (pos.count(s[i])) {
                if (pos[s[i]] >= begin_pos) {
                    begin_pos = pos[s[i]] + 1;
                }
            }
            pos[s[i]] = i;
            longest = max(longest, i - begin_pos + 1);
        }
        return longest;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 像sliding window
        // 用map记录char index
        // 每一步，先更新start位置为max(start, map[s[i]])，再更新max_len
        // 注意，为了算第一个char， start要从-1开始
        int max_len = 0;
        int start = -1;
        unordered_map<char, int> loc;
        for (int i = 0; i < s.length(); i++) {
            if (loc.count(s[i])) {
                start = max(start, loc[s[i]]);
            }
            loc[s[i]] = i;
            max_len = max(max_len, i - start);
        }
        return max_len;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1;
        int max_len = 0;
        unordered_map<char, int> last_idx_map;
        for (int i = 0; i < s.length(); i++) {
            if (last_idx_map.find(s[i]) != last_idx_map.end()) {
                start = max(start, last_idx_map[s[i]]); 
            }
            max_len = max(max_len, i - start);
            last_idx_map[s[i]] = i;
        }
        return max_len;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_map;
        int current_length = 0;
        int longest_length = 0;
        int substring_left_pos = 0;
        int substring_right_pos = 0;

        //TODO: bad way to find the end of string
        while (s[substring_right_pos] != '\0') {
            if (char_map.find(s[substring_right_pos]) != char_map.end()) {
                current_length = substring_right_pos - substring_left_pos;
                if (current_length > longest_length) {
                    longest_length = current_length;
                }

                if (char_map[s[substring_right_pos]] + 1 > substring_left_pos) {
                    substring_left_pos = char_map[s[substring_right_pos]] + 1;
                }
            }

            char_map[s[substring_right_pos]] = substring_right_pos;
            substring_right_pos++;
        }

        current_length = substring_right_pos - substring_left_pos;
        if (current_length > longest_length) {
            longest_length = current_length;
        }

        return longest_length;
    }
};
