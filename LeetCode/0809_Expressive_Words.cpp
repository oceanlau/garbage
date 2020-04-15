class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        for (const string& word : words) {
            int i = 0;
            int j = 0;
            for (; i < S.length(); i++) {
                if (j < word.length() && S[i] == word[j]) {
                    j ++;
                } else if (i > 0 && i < S.length() - 1 && S[i - 1] == S[i] && S[i] == S[i + 1]) {
                    i++;
                } else if (i > 1 && i < S.length() &&  S[i - 2] == S[i - 1] && S[i - 1] == S[i]){
                } else {
                    break;
                }
            }
            if (j == word.length() && i == S.length()) {
                ans++;
            }
        }
        return ans;
    }
};
