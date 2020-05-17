class Solution {
private:
    int expand(string& s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            count ++;
            i --;
            j ++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            cnt += expand(s, i, i);
            cnt += expand(s, i, i + 1);
        }
        return cnt;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int cnt = s.length();
        for (int i = 0; i < s.length(); i++) {
            int d = 1;
            int j = i;
            while (j >= 0 && i + d < s.length() && s[j] == s[i+d]) {
                cnt ++;
                j--;
                d++;
            }
            d = 1;
            j = i - 1;
            while (j >= 0 && i + d < s.length() && s[j] == s[i+d]) {
                cnt ++;
                j--;
                d++;
            }
        }
        return cnt;
    }
};
