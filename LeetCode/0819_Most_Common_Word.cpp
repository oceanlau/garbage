class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> blacklist(banned.begin(), banned.end());
        for (char& c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }
        stringstream ss(paragraph);
        string word;
        unordered_map<string, int> freq;
        string max_freq_w = "";
        int max_freq = 0;
        while (getline(ss, word, ' ')) {
            if (word == "") {
                continue;
            }
            freq[word]++;
            if (!blacklist.count(word) && freq[word] > max_freq) {
                max_freq = freq[word];
                max_freq_w = word;
            }
        }
        return max_freq_w;
    }
};

//96% 92%
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int max_cnt = 0;
        string max_w = "";
        unordered_map<string, int> count;
        for (string w : banned) {
            for (int i = 0; i < w.length(); i++) {
                int cnum = w[i] - 'A';
                if (cnum >= 0 && cnum < 26) {
                    w[i] = (char) ('a' + cnum);
                }
            }
            count[w] = -1;
        }
        
        for(int i = -1, j = 0; j <= paragraph.length(); j ++) {
            int cnum = paragraph[j] - 'A';
            if (cnum >= 0 && cnum < 26) {
                paragraph[j] = (char) ('a' + cnum);
            }
            cnum = paragraph[j] - 'a';
            //Watch the corner case!
            if (cnum >= 26 || cnum < 0 || j == paragraph.length()) {
                if (i != -1 && j - i != 0) {
                    string w = paragraph.substr(i, j - i);
                    if (count[w] != -1) {
                        count[w] ++;
                        if (count[w] > max_cnt) {
                            max_cnt = count[w];
                            max_w = w;
                        }
                    }
                }
                i = -1;
            } else if (i == -1) {
                i = j;
            }
        }
        return max_w;
    }
};
