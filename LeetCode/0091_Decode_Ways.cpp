// still 66%
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        //num of ways to decode starting from a position
        vector<int> nums(len, -1);
        len --;
        if (s[len] == '0') {
            nums[len] = 0;
        } else {
            nums[len] = 1;
        }
        if (len == 0) {
            return nums[len];
        }
        len --;
        if (s[len] == '0') {
            nums[len] = 0;
        } else {
            if (s[len] == '1' || (s[len] == '2' && s[len + 1] < '7')) {
                nums[len] = nums[len + 1] + 1;
            } else if (s[len + 1] == '0') {
                nums[len] = 0;
            } else {
                nums[len] = 1;
            }
        }
        while (--len >= 0) {
            if (s[len] == '0') {
                nums[len] = 0;
            } else {
                nums[len] = nums[len + 1];
                if (s[len] == '1' || (s[len] == '2' && s[len + 1] < '7')) {
                    nums[len] += nums[len + 2];
                }
            }
        }
        return nums[0];
    }
};

// DP, only 66%
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        //num of ways to decode starting from a position
        vector<int> nums(len, -1);
        len --;
        if (s[len] - '0' > 0) {
            nums[len] = 1;
        } else {
            nums[len] = 0;
        }
        if (len == 0) {
            return nums[len];
        }
        len --;
        if (s[len] - '0' > 0) {
            if (stoi(s.substr(len, 2)) <= 26) {
                nums[len] = nums[len + 1] + 1;
            } else if (s[len + 1] == '0') {
                nums[len] = 0;
            } else {
                nums[len] = 1;
            }
        } else {
            nums[len] = 0;
        }
        while (--len >= 0) {
            if (s[len] - '0' > 0) {
                nums[len] = nums[len + 1];
                if (stoi(s.substr(len, 2)) <= 26) {
                    nums[len] += nums[len + 2];
                }
            } else {
                nums[len] = 0;
            }
        }
        return nums[0];
    }
};

// Time Limit Exceeded
class Solution {
private:
    void _getDp(int& num, int start, string& s, int len) {
        if (start == len) {
            num ++;
            return;
        }
        if (start < len && s[start] - '0' > 0) {
            _getDp(num, start + 1, s, len);
            if (start + 1 < len) {
                int tmp = stoi(s.substr(start, 2));
                if ( tmp > 0 && tmp <= 26) {
                    _getDp(num, start + 2, s, len);
                }
            }
        }
    }
public:
    int numDecodings(string s) {
        int num = 0;
        _getDp(num, 0, s, s.length());
        return num;
    }
};
