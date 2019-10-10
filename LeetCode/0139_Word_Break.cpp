// 45% 49%
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // means empty. Not include first char.
        vector<int> valid_pos{0};
        // Not include char at i
        for (int i = 0; i <= s.length(); i++) {
            for (const int j : valid_pos) {
                if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
                    valid_pos.push_back(i);
                    break;
                }
            }
        }
        return valid_pos.back() == s.length();
    }
};
