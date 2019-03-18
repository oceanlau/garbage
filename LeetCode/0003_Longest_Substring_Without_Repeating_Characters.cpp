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
