class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> window (26, 0);
        int window_len = 0;
        vector<int> target(26, 0);
        for (const char c : p) {
            target[c - 'a']++;
        }
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (j < s.length()) {
            window[s[j++] - 'a']++;
            if (window_len < p.length()) {
                window_len ++;
            } else {
                window[s[i++] - 'a']--;
            }
            if (window_len == p.length() && window == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        string p_counter(26, '0');
        string s_counter(26, '0');
        for (int i = 0; i < p.length(); i++) {
            p_counter[p[i] - 'a'] ++;
        }
        int d = p.length();
        for (int i = 0; i < s.length(); i++) {
            s_counter[s[i] - 'a'] ++;
            if (i >= d) {
                s_counter[s[i - d] - 'a'] --;
            }
            if (i >= d - 1 && s_counter == p_counter) {
                res.push_back(i - d + 1);
            }
        }
        return res;
    }
};
