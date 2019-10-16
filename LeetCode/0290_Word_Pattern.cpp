// 100% 100%
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i = 0;
        int j = 0;
        vector<string> dict(26, "");
        while (i < pattern.length() && j < str.length()) {
            int begin = j;
            while (j < str.length() && str[j] != ' ') {
                j ++;
            }
            string token = str.substr(begin, j - begin);
            if (dict[pattern[i] - 'a'] == "") {
                if (find(dict.begin(), dict.end(), token) != dict.end()) {
                    return false;
                }
                dict[pattern[i] - 'a'] = token;
            } else {
                if (dict[pattern[i] - 'a'] != token) {
                    return false;
                }
            }
            i++;
            // Extra careful with these corner cases!
            if (j != str.length()) {
                j ++;
            }
        }
        if (i == pattern.length() && j == str.length()) {
            return true;
        }
        return false;
        
    }
};
