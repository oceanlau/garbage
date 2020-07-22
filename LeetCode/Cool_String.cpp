class Solution {
public:
    bool coolString(string s) {
        unordered_map<char, int> freq;
        for (const char c : s) {
            freq[c] ++;
        }
        unordered_map<int, int> f_freq;
        for (auto p : freq) {
            f_freq[p.second] ++;
        }
        if (f_freq.size() > 2) {
            return false;
        }
        if (f_freq.size() == 1) {
            return true;
        }
        if (f_freq.begin()->second > 1) {
            return f_freq.rbegin()->first - f_freq.begin()->first == 1;
        }
        return f_freq.begin()->first - f_freq.rbegin()->first == 1;
    }
};
