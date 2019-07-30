class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> t_vec(128, 0);
        for (char t_c : t) {
            t_vec[t_c]++;
        }
        int start = 0;
        int end = 0;
        int min = INT_MAX;
        int min_start = 0;
        int required = t.length();
        while (end <= s.length() && start < s.length()) {
            if (required) {
                t_vec[s[end]]--;
                if (t_vec[s[end]] >= 0) {
                    required--;
                }
                end++;
            } else {
                if (end - start < min) {
                    min = end - start;
                    min_start = start;
                }
                t_vec[s[start]]++;
                if (t_vec[s[start]] > 0) {
                    required++;
                }
                start ++;
            }
        }
        return min == INT_MAX ? "" : s.substr(min_start, min);
    }
};
