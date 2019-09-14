// optimized
class Solution {
public:
    int numDistinct(string s, string t) {
        int t_len = t.length();
        int s_len = s.length();
        vector<unsigned> dp(t_len + 1, 0);
        
        int pre = 0;
        for (int j = 0; j < s_len + 1; j ++) {
            for (int i = 0; i < t_len + 1; i++) {
                if (i == 0) {
                    dp[i] = 1;
                    pre = dp[i];
                } else if (j == 0) {
                    dp[i] = 0;
                    pre = dp[i];
                } else {
                    int tmp = dp[i];
                    dp[i] = (t[i-1] == s[j-1]) ? dp[i] + pre : dp[i];
                    pre = tmp;
                }
            }
        }
        return dp[t_len];
    }
};

//however this would work
class Solution {
public:
    int numDistinct(string s, string t) {
        int t_len = t.length();
        int s_len = s.length();
        vector<vector<unsigned>> dp(t_len + 1, vector<unsigned>(s_len + 1, 0));
        
        for (int i = 0; i < t_len + 1; i++) {
            for (int j = 0; j < s_len + 1; j ++) {
                if (i == 0) {
                    dp[i][j] = 1;
                } else if (j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = (t[i-1] == s[j-1]) ? dp[i][j-1] + dp[i-1][j-1] : dp[i][j-1];
                }
            }
        }
        return dp[t_len][s_len];
    }
};


//hidden bug, certain long test case would fail
//did not find out why

class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.length() > s.length()) {
            return 0;
        }
        if (t.length() == 0 || s.length() == 0) {
            return 1;
        }
        vector<vector<unsigned>> dp(t.length(), vector<unsigned>(s.length(), 0));
        for (int i = 0; i < t.length(); i++) {
            for (int j = 0; j < s.length(); j ++) {
                if (j == 0) {
                    // j == 0 || (j == 0 && i == 0)
                    dp[i][j] = (t[i] == s[j]) ? 1 : 0;
                } else if (i == 0) {
                    // i == 0 except (j == 0 && i == 0)
                    dp[i][j] = (t[i] == s[j]) ? 1 + dp[i][j-1] : dp[i][j-1];
                } else {
                    dp[i][j] = (t[i] == s[j]) ? dp[i][j-1] + dp[i-1][j-1] : dp[i][j-1];
                }
            }
        }
        return dp[t.length() - 1][s.length() - 1];
    }
};
