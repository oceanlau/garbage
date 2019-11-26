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
