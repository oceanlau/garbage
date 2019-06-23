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
