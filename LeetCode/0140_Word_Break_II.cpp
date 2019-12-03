//solve the problem twice... still got 99% 97%
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        int min_len = s.length();
        int max_len = 0;
        for (const string& word : wordDict) {
            min_len = min(min_len, (int)word.length());
            max_len = max(max_len, (int)word.length());
        }
        
        vector<bool> dp(s.length() + 1, false);// dp[i] -> s[0, i) could be seged
        dp[0] = true;
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = i - min_len; j >= max(0, i - max_len); j --) {
                if (dp[j]) {
                    if (wordDictSet.count(s.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        if (!dp[s.length()]) {
            return {};
        }
        
        unordered_map<int, vector<string>> pos_ans;// derived from dp in word break I
        /*
        // backward BFS to reconstruct the path
        pos_ans[s.length()] = {""};
        */
        pos_ans[0] = {""};
        
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = i - min_len; j >= 0; j --) {
                if (pos_ans.count(j)) {
                    if (j < i - max_len) {
                        pos_ans.erase(j);
                    } else {
                        string candidate = s.substr(j, i - j);
                        if (wordDictSet.count(candidate)) {
                            for (int k = 0; k < pos_ans[j].size(); k++) {
                                if (pos_ans[j][k] == "") {
                                    pos_ans[i].push_back(candidate);
                                } else {
                                    pos_ans[i].push_back(pos_ans[j][k] + " " + candidate);
                                }
                            }
                        }
                    }
                }
            }
        }
        return pos_ans[s.length()];
    }
};


//try to avoid MLE using forward DP, still does not work
//good answer in an interview?
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        //just to avoid MLE
        int min_len = s.length();
        int max_len = 0;
        for (const string& word : wordDict) {
            min_len = min(min_len, (int)word.length());
            max_len = max(max_len, (int)word.length());
        }
        unordered_map<int, vector<string>> pos_ans;// derived from dp in word break I
        pos_ans[0] = {""};
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = i - min_len; j >= 0; j --) {
                if (pos_ans.count(j)) {
                    if (j < i - max_len) {
                        pos_ans.erase(j);
                    } else {
                        string candidate = s.substr(j, i - j);
                        if (wordDictSet.count(candidate)) {
                            for (int k = 0; k < pos_ans[j].size(); k++) {
                                if (pos_ans[j][k] == "") {
                                    pos_ans[i].push_back(candidate);
                                } else {
                                    pos_ans[i].push_back(pos_ans[j][k] + " " + candidate);
                                }
                            }
                        }
                    }
                }
            }
        }
        return pos_ans[s.length()];
    }
};
