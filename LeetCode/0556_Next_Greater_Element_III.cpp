class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.length() - 1;
        for (; i > 0; i--) {
            if (s[i - 1] < s[i]) {
                break;
            }
        }
        if (i == 0) {
            return -1;
        }
        int j = i - 1;
        for (;i < s.length(); i++) {
            if (s[i] <= s[j]) {
                break;
            }
        }
        i = i - 1;
        swap(s[j], s[i]);
        reverse(s.begin() + j + 1, s.end());
        long long res = stoll(s);
        if (res > INT_MAX) {
            return -1;
        }
        return res;
    }
};
