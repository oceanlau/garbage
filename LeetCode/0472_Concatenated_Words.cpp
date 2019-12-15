class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        for (const string& word : words) {
            vector<bool> dp(word.length() + 1, false);
            dp[0] = true;
            for (int i = 0; i <= word.length(); i++) {
                for (int j = i - 1; j >= 0; j--) {
                    string part = word.substr(j, i - j);
                    if (dp[j] && dict.count(part)) {
                        if (j == 0 && i == word.length()) {
                            continue;
                        }
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (word.length() > 0 && dp[word.length()]) {
                res.push_back(word);
            }
        }
        return res;
    }
};
