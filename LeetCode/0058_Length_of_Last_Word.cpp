class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int tmp_len = 0;
        for(auto iter = s.begin(); iter != s.end(); iter ++) {
            if (*iter != ' ') {
                tmp_len += 1;
                len = tmp_len;
            } else {
                tmp_len = 0;
            }
        }
        return len;
    }
};
