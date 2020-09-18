class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i <= n / 2; i ++) {
            if (s[i] != s[n - i - 1]) {
                int l = i;
                int r = n - i - 1;
                int nl = l + 1;
                int nr = r;
                bool flag = true;
                while (nl < nr) {
                    if (s[nl ++] != s[nr --]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
                nl = l;
                nr = r - 1;
                flag = true;
                while (nl < nr) {
                    if (s[nl ++] != s[nr --]) {
                        flag = false;
                        break;
                    }
                }
                return flag;
            }
        }
        return true;
    }
};

//See below. Code would be much simpler if we just use two pointer
class Solution {
private:
    bool is_palindrome(string s, int k) {
        int s_len = s.length();
        if (s_len <= 0) {
            return true;
        }
        int i = 0;
        while (s_len - 1 - i - i >= 0 && s[i] == s[s_len - 1 - i]) {
            i++;
        }
        if (s_len - 1 - i - i < 0) {
            return true;
        } else if (k > 0){
            return is_palindrome(s.substr(i, s_len - 1 - i - i), k - 1) || is_palindrome(s.substr(i + 1, s_len - 1 - i - i), k - 1);
        } else {
            return false;
        }
    }
public:
    bool validPalindrome(string s) {
        int k = 1;
        return is_palindrome(s, k);
    }
};

//What's the time complexity of this?
class Solution {
private:
    bool is_palindrome(string s, int k) {
        if (s.length() <= 0) {
            return true;
        }
        if (s[0] == s[s.length() - 1]) {
            return is_palindrome(s.substr(1, s.length() - 2), k);
        }
        if (k > 0) {
            return is_palindrome(s.substr(0, s.length() - 1), k - 1) || is_palindrome(s.substr(1, s.length() - 1), k - 1);
        } else {
            return false;
        }
    }
public:
    bool validPalindrome(string s) {
        int k = 1;
        return is_palindrome(s, k);
    }
};



//53% 9%
class Solution {
private:
    bool validPalindrome(string s, int i, int j, int k) {
        while (i < j) {
            if (s[i] != s[j]) {
                if (k > 0) {
                    k --;
                    return validPalindrome(s, i + 1, j, k) || validPalindrome(s, i, j - 1, k);
                } else {
                    return false;
                }
            }
            i ++;
            j --;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        if (s.length() < 2) {
            return true;
        }
        return validPalindrome(s, 0, s.length() - 1, 1);
    }
};
