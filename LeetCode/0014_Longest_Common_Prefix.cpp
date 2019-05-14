// Brute
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (0 == strs.size()) {
            return "";
        }
        string lcp = "";
        int i = 0;
        char last_c = '\0';
        bool is_end = false;
        while (true) {
            last_c = '\0';
            for (string item : strs) {
                if (item.length() > i && (last_c == '\0' || last_c == item[i])) {
                    last_c = item[i];
                } else {
                    is_end = true;
                    break;
                }
            }
            if (is_end) {
                break;
            }
            lcp += last_c;
            i++;
        }
        return lcp;
        
    }
};
