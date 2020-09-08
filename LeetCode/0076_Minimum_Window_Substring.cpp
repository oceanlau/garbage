class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() == 0) {
            return "";
        }
        vector<int> s_counter(256, 0);
        vector<int> t_counter(256, 0);
        int t_total = t.length();
        for (const char c : t) {
            t_counter[c] ++;
        }
        int min_len = INT_MAX;
        string min_window = "";
        for (int l = 0, r = 0; r < s.length(); r ++) {
            if (t_counter[s[r]] > 0) {
                if (s_counter[s[r]] ++ < t_counter[s[r]]) {
                    t_total --;
                }
            }
            if (t_total == 0) {
                while (l <= r && t_total == 0) {
                    if (t_counter[s[l]] > 0) {
                        if (-- s_counter[s[l]] < t_counter[s[l]]) {
                            t_total ++;
                        }
                    }
                    l ++;
                }
                if (r - l + 2 < min_len) {
                    min_len = r - l + 2;
                    min_window = s.substr(l - 1, min_len);
                }
            }
        }
        return min_window;
    }
};

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
