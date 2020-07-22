class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char, int> freq;
        for (int i = 0; i < minSize; i ++) {
            freq[s[i]] ++;
        }
        int max_freq = 0;
        unordered_map<string, int> substrings;
        if (freq.size() <= maxLetters) {
            substrings[s.substr(0, minSize)] ++;
            max_freq = 1;
        }
        int l = 0;
        for (int r = minSize; r < s.length(); r++) {
            freq[s[r]] ++;
            if (-- freq[s[l]] == 0) {
                freq.erase(s[l]);
            }
            l ++;
            if (freq.size() <= maxLetters) {
                if (++ substrings[s.substr(l, minSize)] > max_freq) {
                    max_freq = substrings[s.substr(l, minSize)];
                }
            }
        }
        return max_freq;
    }
};
