//cached
class Solution {
private:
    string _s;
    string _p;
    //cached match result of substring from i of _s and j of _p
    vector<vector<short>> _dp;
    short _getDp(int i, int j) {
        if (_dp[i][j] != -1) {
            return _dp[i][j];
        }
        
        if (j == _p.length()) {
            if (i == _s.length()) {
                _dp[i][j] = 1;
            } else {
                _dp[i][j] = 0;
            }
        } else if (_p[j] == '*') {
            int skip = 1;
            while (_p[j + skip] == '*') {
                skip ++;
            }
            if (i == _s.length()) {
                _dp[i][j] = _getDp(i, j + skip);
            } else {
                _dp[i][j] = _getDp(i, j + skip) || _getDp(i + 1, j);
            }
        } else if (_p[j] == '?') {
            if (i == _s.length()) {
                _dp[i][j] = 0;
            } else {
                _dp[i][j] = _getDp(i + 1, j + 1);
            }
        } else {
            if (i == _s.length() || _s[i] != _p[j]) {
                _dp[i][j] = 0;
            } else {
                _dp[i][j] = _getDp(i + 1, j + 1);
            }
        }
        return _dp[i][j];
    }
public:
    bool isMatch(string s, string p) {
        _s = s;
        _p = p;
        int s_len = s.length();
        int p_len = p.length();
        _dp.resize(s_len+1, vector<short>(p_len+1, -1));
        _dp[s_len][p_len] = 1;

        return _getDp(0, 0) == 1;
        
    }
};

// too slow
class Solution {
public:
    bool isMatch(string s, string p) {        
        if (p.length() == 0) {
            if (s.length() == 0) {
                return true;
            }
            return false;
        } else if (p[0] == '*') {
            if (s.length() == 0) {
                return isMatch(s, p.substr(1));
            }
            int i = 1;
            while (p[i] == '*') {
                i ++;
            }
            return isMatch(s, p.substr(i)) || isMatch(s.substr(1), p);
        } else if (p[0] == '?') {
            if (s.length() == 0) {
                return false;
            }
            return isMatch(s.substr(1), p.substr(1));
        } else {
            if (s.length() == 0 || s[0] != p[0]) {
                return false;
            }
            return isMatch(s.substr(1), p.substr(1));
        }
        
    }
};
