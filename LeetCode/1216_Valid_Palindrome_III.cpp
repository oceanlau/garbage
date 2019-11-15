//Pass string by ref.. Then 74% 100%
class Solution {
private:
    int validPalindrome(string& s, int i, int j, vector<vector<int>>& removedCnt) {
        if (removedCnt[i][j] != -1) {
            return removedCnt[i][j];
        }
        if (s[i] == s[j]) {
            if (i + 2 < j) {
                removedCnt[i][j] = validPalindrome(s, i + 1, j - 1, removedCnt);
            } else {
                removedCnt[i][j] = 0;
            }
        } else {
            removedCnt[i][j] = 1 + min(validPalindrome(s, i + 1, j, removedCnt), validPalindrome(s, i, j - 1, removedCnt));
        }
        return removedCnt[i][j];
    }
public:
    bool isValidPalindrome(string s, int k) {
        if (s.length() < 2) {
            return true;
        }
        vector<vector<int>> removedCnt(s.length(), vector<int>(s.length(), -1));
        return validPalindrome(s, 0, s.length() - 1, removedCnt) <= k;
    }
};

//MLE
class Solution {
private:    
    int validPalindrome(string s, int i, int j, vector<vector<int>>& removedCnt) {
        if (removedCnt[i][j] != -1) {
            return removedCnt[i][j];
        }
        if (s[i] == s[j]) {
            if (i + 2 < j) {
                removedCnt[i][j] = validPalindrome(s, i + 1, j - 1, removedCnt);
            } else {
                removedCnt[i][j] = 0;
            }
        } else {
            removedCnt[i][j] = 1 + min(validPalindrome(s, i + 1, j, removedCnt), validPalindrome(s, i, j - 1, removedCnt));
        }
        return removedCnt[i][j];
    }
public:
    bool isValidPalindrome(string s, int k) {
        if (s.length() < 2) {
            return true;
        }
        vector<vector<int>> removedCnt(s.length(), vector<int>(s.length(), -1));
        return validPalindrome(s, 0, s.length() - 1, removedCnt) <= k;
    }
};

//Still TLE. Wrong way to do dp. Cache too sparse.
class Solution {
private:
    int validPalindrome(string s, int i, int j, int k, vector<vector<int>>& isValidDP) {
        if (isValidDP[i][j] != -1) {
            return isValidDP[i][j];
        }
        int tmpi = i;
        int tmpj = j;
        while (i < j) {
            if (s[i] != s[j]) {
                if (k > 0) {
                    k --;
                    return validPalindrome(s, i + 1, j, k, isValidDP) || validPalindrome(s, i, j - 1, k, isValidDP) || validPalindrome(s, i + 1, j - 1, k - 1, isValidDP);
                } else {
                    isValidDP[i][j] = 0;
                    return 0;
                }
            }
            i ++;
            j --;
        }
        isValidDP[tmpi][tmpj] = 1;
        return 1;
    }
public:
    bool isValidPalindrome(string s, int k) {
        if (s.length() < 2) {
            return true;
        }
        vector<vector<int>> isValidDP (s.length(), vector<int>(s.length(), -1));
        return validPalindrome(s, 0, s.length() - 1, k, isValidDP) == 1;
    }
};

//MLE TLE
class Solution {
private:
    bool validPalindrome(string s, int i, int j, int k) {
        while (i < j) {
            if (s[i] != s[j]) {
                if (k > 0) {
                    k --;
                    return validPalindrome(s, i + 1, j, k) || validPalindrome(s, i, j - 1, k) || validPalindrome(s, i + 1, j - 1, k - 1);
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
    bool isValidPalindrome(string s, int k) {
        if (s.length() < 2) {
            return true;
        }
        return validPalindrome(s, 0, s.length() - 1, k);
    }
};
