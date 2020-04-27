class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> dp(n, -1); //after fill row i, the idx in sentence begining next row
        for (int i = 0; i < dp.size(); i++) {
            int j = i;
            int len = sentence[j].length();
            // does not fit
            if (len > cols) {
                return 0;
            }
            while (len <= cols) {
                len += 1 + sentence[++j % n].length();
            }
            dp[i] = j; // not inc j
        }
        int word_cnt = 0;
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            word_cnt += dp[idx] - idx;
            idx = dp[idx] % n;
        }
        return word_cnt / n;
    }
};
