class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int max_len = 0;
        int l = 0;
        int k = 2;
        unordered_map<char, int> char_last_pos_map;
        for (int r = 0; r < s.length(); r ++) {
            if (char_last_pos_map.find(s[r]) == char_last_pos_map.end()) {
                char_last_pos_map[s[r]] = r;
                if (k > 0) {
                    k --;
                } else {
                    l = s.length(); //max it
                    unordered_map<char, int>::iterator it_to_remove;
                    for (auto it = char_last_pos_map.begin(); it != char_last_pos_map.end(); it++) {
                        if (it->second + 1 < l) {
                            l = it->second + 1; // k > 0, so l wont pass r in position, wont overflow
                            it_to_remove = it;
                        }
                    }
                    char_last_pos_map.erase(it_to_remove);
                }
            } else {
                char_last_pos_map[s[r]] = r;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};
