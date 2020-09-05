class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for (int l = len / 2; l > 0; l--) {
            if (len % l == 0) {
                string part = s.substr(0, l);
                string middle = s.substr(l);
                if (middle + part == part + middle) {
                    return true;
                }
            }
        }
        return false;
    }
};
