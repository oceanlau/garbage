class Solution {
public:
    int longestValidParentheses(string s) {
        // longest_at
        vector<int> dp(s.length(), 0);
        int longest = 0;
        for (int i = 1; i < s.length(); i ++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (i - 2 >= 0) {
                        dp[i] = 2 + dp[i - 2];
                    } else {
                        dp[i] = 2;
                    }
                } else if (i - 1 >= 0 && dp[i - 1] > 0) {
                    if (i - dp[i - 1] - 1 >= 0) {
                        if (s[i - dp[i - 1] - 1] == '(') {
                            dp[i] = 2 + dp[i - 1];
                            if (i - dp[i - 1] - 2 >= 0) {
                                dp[i] += dp[i - dp[i - 1] - 2];
                            }
                        }
                    }
                }
            }
            longest = max(longest, dp[i]);
        }
        return longest;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        int l = 0;
        int r = 0;
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            len ++;
            if (s[i] == '(') {
                l ++;
            } else {
                r ++;
                if (r == l) {
                    max_len = max(max_len, len);
                } else if (r > l) {
                    l = 0;
                    r = 0;
                    len = 0;
                }
            }
        }
        
        l = 0;
        r = 0;
        len = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            len ++;
            if (s[i] == ')') {
                l ++;
            } else {
                r ++;
                if (r == l) {
                    max_len = max(max_len, len);
                } else if (r > l) {
                    l = 0;
                    r = 0;
                    len = 0;
                }
            }
        }
        
        return max_len;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> l_pos;
        int max_len = 0;
        int start_loc = -1;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                l_pos.push(i);
            } else {
                if (!l_pos.empty()) {
                    l_pos.pop();
                    int l = start_loc;
                    if (!l_pos.empty()) {
                        l = max(l, l_pos.top());
                    }
                    max_len = max(max_len, i - l);
                } else {
                    start_loc = i;
                }
            }
        }
        return max_len;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int longest = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i > 1) {
                        dp[i] += dp[i-2];
                    }
                } else if (dp[i - 1] > 0){
                    int matching_location = i - dp[i - 1] - 1;
                    if (matching_location >= 0 && s[matching_location] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (-- matching_location >= 0) {
                            dp[i] += dp[matching_location];
                        }
                    }
                }
                longest = max(longest, dp[i]);
            }
        }
        return longest;
    }
};

//dp
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int longest = 0;
        int i = 1;
        while (i < s.length()) {
            if (s[i] == '(') {
                i ++;
                continue;
            }
            if (s[i-1] == ')') {
                int correspond = i - dp[i-1] - 1;
                if (correspond >= 0 && s[correspond] == '(') {
                    if (correspond - 1 > 0) {     
                        dp[i] = dp[i-1] + 2 + dp[correspond - 1];          
                    } else {
                        dp[i] = dp[i-1] + 2;
                    }
                }
            } else {
                if (i-2 >= 0) {               
                    dp[i] = dp[i-2] + 2;
                } else {
                    dp[i] = 2;
                }
            }
            longest = max(dp[i], longest);
            i ++;
        }
        return longest;
        
    } 
};

//wrong thinking
class Solution {
public:
    int longestValidParentheses(string s) {
        unsigned len = s.length();
        unsigned i = 0;
        int start = 0;
        int balance = 0;
        unordered_map<int, int> m;
        int longest = 0;
        int distance = 0;
        while (i < len) {
            if (s[i] == '('){
                if (balance < 0){
                    m.clear();
                    balance = 1;
                } else {
                    balance ++;
                }
                if (m.find(balance) == m.end()) {
                    m[balance] = i;
                }
            } else {
                balance --;
                if (balance < 0) {
                    i ++;
                    continue;
                }
                if (m.find(balance + 1) != m.end()) {
                    distance = i - m[balance + 1] + 1;
                    if (distance > longest) {
                        longest = distance;
                    }
                    //if (balance == 0) {
                    //    start = m[balance + 1];
                    //    m.clear();
                    //}
                }
            }
            i ++;
        }
        return longest;
        
    } 
};

//wrong thinking again: "())()(()"
class Solution {
private:    
    int _findLongest(string::iterator i, string::iterator j, int balance) {
        while (*i == ')' && i <= j) {
            i ++;
            balance ++;
        }
        while (*j == '(' && j >= i) {
            j --;
            balance --;
        }
        if (j <= i) {
            return 0;
        } else if (balance == 0) {
            return j - i + 1;
        }
        return max(_findLongest(i+1, j, balance-1), _findLongest(i, j-1, balance+1));
    }
public:
    int longestValidParentheses(string s) {
        string::iterator i = s.begin();
        string::iterator j = s.end() - 1;
        unsigned len = j - i + 1;
        if (len < 2) {
            return 0;
        }
        size_t l_count = count(i, j + 1, '(');
        int balance = l_count - (len - l_count);
        return _findLongest(i, j, balance);        
    }
    
    
};

//wrong thinking
class Solution {
private:
    int _trim(string::iterator& i, string::iterator& j, int balance) {
        while (*i != '(' && i <= j) {
            i ++;
            balance ++;
        }
        while (*j != ')' && j >= i) {
            j --;
            balance --;
        }
        return balance;
    }
public:
    int longestValidParentheses(string s) {
        string::iterator i = s.begin();
        string::iterator j = s.end() - 1;
        _trim(i, j, 0);
        if (j <= i) {
            return 0;
        }
        unsigned len = j - i + 1;
        size_t l_count = count(i, j + 1, '(');
        int balance = l_count - (len - l_count);
        while (balance != 0) {
            if (j <= i) {
                return 0;
            }
            if (balance < 0) {
                balance = _trim(i, --j, balance+1);
            } else {
                balance = _trim(++i, j, balance-1);
            }
        }
        return (j - i + 1);
        
    }
    
};
