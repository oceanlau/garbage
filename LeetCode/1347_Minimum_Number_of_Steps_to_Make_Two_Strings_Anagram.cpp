class Solution {
public:
    int minSteps(string s, string t) {
        // count each char, either
        // - use the number of chars s has t doesn't
        // - or use the number of chars t has s doesn't
        vector<int> cnts(26, 0);
        for (int i = 0; i < s.length(); i++) {
            cnts[s[i] - 'a'] ++;
            cnts[t[i] - 'a'] --;
        }
        int ans = 0;
        for (const int cnt : cnts) {
            /*
            if (cnt > 0) {
                ans += cnt;
            }
            */
            if (cnt < 0) {
                ans += cnt;
            }
        }
        return -ans;
    }
};
