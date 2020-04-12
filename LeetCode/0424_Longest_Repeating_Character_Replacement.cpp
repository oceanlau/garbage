class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxlen = 0;
        int consensus_cnt = 0;
        vector<int> char_cnt(26, 0);
        for (int r = 0; r < s.length(); r++) {
            consensus_cnt = max(consensus_cnt, ++char_cnt[s[r] - 'A']);
            while (r - l + 1 - consensus_cnt > k) {
                char_cnt[s[l ++] - 'A']--;
                consensus_cnt = 0;
                for (const int cnt : char_cnt) {
                    consensus_cnt = max(consensus_cnt, cnt);
                }
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
