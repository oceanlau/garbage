class Solution {
public:
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        dp.resize(s.length() + 1, vector<int> (p.length() + 1, -1));
        return isMatch(0, s, 0, p);
    }
    int isMatch(int i, string s, int j, string p) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (j == p.length()) {
            dp[i][j] = (i == s.length());
        } else if (j < p.length() - 1 && p[j + 1] == '*') {
            if (i < s.length() && (s[i] == p[j] || p[j] == '.')) {
                dp[i][j] = isMatch(i, s, j + 2, p)
                           || isMatch(i + 1, s, j + 2, p)
                           || isMatch(i + 1, s, j, p);
            } else {
                dp[i][j] = isMatch(i, s, j + 2, p);
            }
        } else if (i < s.length() && (s[i] == p[j] || p[j] == '.')) {
            dp[i][j] = isMatch(i + 1, s, j + 1, p);
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        // backtrack, read two char at p a time
        bool canskip = false;
        bool thismatch = false;
        if (p.length() > 1 && p[1] == '*') {
            canskip = true;
        } else if (p.length() == 0) {
            return s.length() == 0;
        }
        if (s.length() > 0 && (p[0] == '.' || s[0] == p[0])) {
            thismatch = true;
        }
        if (canskip && thismatch) {
            return isMatch(s.substr(1), p)
                || isMatch(s.substr(1), p.substr(2))
                || isMatch(s, p.substr(2));
        } else if (canskip) {
            return isMatch(s, p.substr(2));
        } else if (thismatch) {
            return isMatch(s.substr(1), p.substr(1));
        }
        return false;
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool> (p.length() + 1, false));
        dp[0][0] = true;
        for (int j = 0; j < p.length(); j++) {
            if (p[j] == '*') {
                if (j == 1) {
                    dp[0][j + 1] = true;
                } else {
                    dp[0][j + 1] = dp[0][j - 1];
                }
            }/* else {
                dp[i + 1][j + 1] = false;
            }*/
        }
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < p.length(); j++) {
                if (s[i] == p[j] || p[j] == '.') {
                    dp[i + 1][j + 1] = dp[i][j];
                } else if (p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i + 1][j - 1]; // match zero time
                    if (s[i] == p[j - 1] || p[j-1] == '.') {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i][j + 1]; // match zero or at least one time
                    }
                }/* else {
                    dp[i + 1][j + 1] = false;
                }*/
            }
        }
        return dp[s.length()][p.length()];
    }
};

// recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        
        if (p.length() < 2) {
            if (s == p) {
                return true;
            } else if ("." == p && s.length() == 1) {
                return true;
            }
            return false;
        } else if ('*' == p[1]) {
            if (s.length() != 0 && (s[0] == p[0] || '.' == p[0])) {
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            }
            return isMatch(s, p.substr(2));
        } else {
            if (s.length() != 0 && (s[0] == p[0] || '.' == p[0])) {
                return isMatch(s.substr(1), p.substr(1));
            }
            return false;
        }
        
        
    }
};

// cached 
class Solution {
public:
    
    bool isMatch(string s, string p) {
        _s = s;
        _p = p;
        unsigned s_len = s.length();
        unsigned p_len = p.length();
        _dp.resize(s_len+1, vector<short>(p_len+1, -1));    
        _dp[s_len][p_len] = 1;
        
        return _getDp(0, 0) == 1;
    }
    
private:
    string _s;
    string _p;
    vector<vector<short>> _dp;
    short _getDp(unsigned i, unsigned j) {
        if (_dp[i][j] != -1) {
            return _dp[i][j];
        }
        
        if (j > _p.length() - 2) {
            if (_s.length() - i == _p.length() - j && (_s[i] == _p[j] || '.' == _p[j])) {
                _dp[i][j] = 1;
                
            } else {
                _dp[i][j] = 0;
            }
            return _dp[i][j];
        } else if ('*' == _p[j+1]) {
            if (i != _s.length() && (_s[i] == _p[j] || '.' == _p[j])) {
                return _getDp(i+1, j) || _getDp(i, j+2);
            }
            return _getDp(i, j+2);
        } else {
            if (i != _s.length() && (_s[i] == _p[j] || '.' == _p[j])) {
                return _getDp(i+1, j+1);
            }
            _dp[i][j] = 0;
            return _dp[i][j];
        }
    }
};

// mistake, partial matching is not allowed
class Solution {
public:
    bool isMatch(string s, string p) {
        auto pit = p.begin();
        for (auto it = s.begin(); it != s.end(); it ++) {
            if (*it == *pit || '.' == *pit) {
                pit ++;
                continue;
            }
            if ('*' == *pit) {
                if (*it == *(pit - 1) || '.' == *(pit - 1)) {
                    continue;
                }
                if (*it == *(pit + 1)) {
                    pit += 2;
                    continue;
                }
            }
            return false;
        }
        if (pit + 1 != p.end()) {
            return false;
        }
        return true;
    }
};
