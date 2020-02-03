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
