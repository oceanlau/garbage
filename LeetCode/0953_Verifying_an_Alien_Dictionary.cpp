//8% 76%
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // build a dict of char - pos
        vector<int> dict(26, -1);
        for (int i = 0; i < order.length(); i++) {
            dict[order[i] - 'a'] = i;
        }
        // for each pair of words
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            bool first_char_diff = false;
        //     check each char
        //     check length
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    if (dict[word1[j] - 'a'] > dict[word2[j] - 'a']) {
                        return false;
                    }
                    first_char_diff = true;
                    break;
                }
            }
            if (first_char_diff) {
                continue;
            }
            if (word1.length() > word2.length()) {
                return false;
            }
        }
        return true;
    }
};
