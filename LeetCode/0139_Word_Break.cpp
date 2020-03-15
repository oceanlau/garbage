class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = i; j >= 0; j--) {
                // i - j careful!
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);// dp[i] -> s[0, i) could be seged
        dp[0] = true;
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = i - 1; j >= 0; j --) {
                if (dp[j]) {
                    if (wordDictSet.count(s.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};

//100% 81%
class Solution {
private:
    bool _wordBreak(string s, int start, vector<string>& wordDict, vector<int>& isBreakable) {
        if (start >= s.length()) {
            return true;
        }
        if (isBreakable[start] != -1) {
            return isBreakable[start] == 1;
        }
        for (const string& word : wordDict) {
            if (s.find(word, start) == start && _wordBreak(s, start + word.length(), wordDict, isBreakable)) {
                isBreakable[start] = 1;
                return true;
            }
        }
        isBreakable[start] = 0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> isBreakable(s.length(), -1);
        return _wordBreak(s, 0, wordDict, isBreakable);
    }
};

//Also TLE
class Solution {
private:
    bool _wordBreak(string s, int start, vector<string>& wordDict) {
        if (start >= s.length()) {
            return true;
        }
        for (const string& word : wordDict) {
            if (s.find(word, start) == start && _wordBreak(s, start + word.length(), wordDict)) {
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return _wordBreak(s, 0, wordDict);
    }
};


//Possible TLE
class Solution {
private:
    bool _wordBreak(string s, int start, unordered_set<string>& wordDict) {
        if (start >= s.length()) {
            return true;
        }
        for (int end = start; end < s.length(); end ++) {
            string tmp = s.substr(start, end - start + 1);
            if (wordDict.find(tmp) != wordDict.end() && _wordBreak(s, end + 1, wordDict)) {
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        return _wordBreak(s, 0, wordDictSet);
    }
};

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
