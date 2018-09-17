class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int string_length = s.length();
        unordered_map<char, int> char_map;

        int i = 0;
        int current_length = 0;
        int longest_length = 0;
        int first_occurence_location = -1;
        int last_occurence_location = -1;
        while (s[i] != '\0') {
            if (char_map.find(s[i]) != char_map.end()) {
                if (first_occurence_location == -1) {
                    first_occurence_location = i;
                }
                if (char_map[s[i]] > last_occurence_location) {
                    last_occurence_location = char_map[s[i]];
                }
                current_length = i - char_map[s[i]];
                if (current_length > longest_length) {
                    longest_length = current_length;
                }
            }
            char_map[s[i]] = i;
            i++;
        }

        if (first_occurence_location > longest_length) {
            longest_length = first_occurence_location;
        }

        if (last_occurence_location != -1 && string_length - 1 - last_occurence_location > longest_length) {
            longest_length = string_length - 1 - last_occurence_location;
        }

        if (longest_length == 0) {
            longest_length = string_length;
        }

        return longest_length;
    }
};