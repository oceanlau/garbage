class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (0 == strs.size()) {
            return "";
        }
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
            i++;
        }
        return strs[0].substr(0, i);
        
    }
};

// Big Perf Boost
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size_strs = strs.size();
        if (0 == size_strs) {
            return "";
        }
        int i = 0;
        char last_c = '\0';
        bool is_end = false;
        while (true) {
            last_c = '\0';
            for (int j = 0; j < size_strs; j++) {
                if (strs[j].length() > i && (last_c == '\0' || last_c == strs[j][i])) {
                    last_c = strs[j][i];
                } else {
                    is_end = true;
                    break;
                }
            }
            if (is_end) {
                break;
            }
            i++;
        }
        return strs[0].substr(0, i);
    }
};
