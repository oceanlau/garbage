// 51% 46%
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> transformer;
        vector<char> used_char;
        for (int i = 0; i != s.length(); i++) {
            if (transformer.find(s[i]) != transformer.end()) {
                if (transformer[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if (find(used_char.begin(), used_char.end(), t[i]) != used_char.end()) {
                    return false;
                }
                transformer[s[i]] = t[i];
                used_char.push_back(t[i]);
            }
        }
        return true;
    }
};
