// 1d dp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<bool> dp(s2.length()+1, false);
        
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j ++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = (s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
                } else if (j == 0) {
                    dp[j] = (s1[i - 1] == s3[i + j - 1] && dp[j]);
                } else {
                    dp[j] = (s1[i - 1] == s3[i + j - 1] && dp[j])
                               || (s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
                }
            }
        }
        
        return dp[s2.length()];
    }
};

// 2d dp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<bool>> dp(s1.length()+1, vector<bool>(s2.length()+1, false));
        
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j ++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
                } else if (j == 0) {
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]);
                } else {
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
                               || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
                }
            }
        }
        
        return dp[s1.length()][s2.length()];
    }
};

// Time Limit Exceeded
class Solution {
private:
    void _interleave_step(string& s1, string& s2, string& s3, int s1_len, int s2_len, int s3_len, int s1_nth, int s2_nth, int s3_nth, bool& flag) {
        if (s1_nth > s1_len || s2_nth > s2_len || s3_nth > s3_len) {
            return;
        }
        if (s3_nth == s3_len) {
            if (s1_nth == s1_len && s2_nth == s2_len) {
                flag = true;
            }
            return;
        }
        if (s1[s1_nth] != s3[s3_nth] && s2[s2_nth] != s3[s3_nth]) {
            return;
        } else {
            if (!flag && s1[s1_nth] == s3[s3_nth]) {
                _interleave_step(s1, s2, s3, s1_len, s2_len, s3_len, s1_nth + 1, s2_nth, s3_nth + 1, flag);
            }
            if (!flag && s2[s2_nth] == s3[s3_nth]) {
                _interleave_step(s1, s2, s3, s1_len, s2_len, s3_len, s1_nth, s2_nth + 1, s3_nth + 1, flag);
            }
        }
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool flag = false;
        _interleave_step(s1, s2, s3, s1.length(), s2.length(), s3.length(), 0, 0, 0, flag);
        return flag;
    }
};
