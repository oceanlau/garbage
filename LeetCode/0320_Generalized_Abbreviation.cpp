class Solution {
private:
    // backtracking start from 0 to end
    // each bt:
    // loop i from give start pos to end
    //   - abbr it, skip letters by starting from i + 2 to end and bt into next layer
    void _bt(int start, string word, string& abbr, vector<string>& abbrs) {
        if (start == word.length()) {
            abbrs.push_back(abbr);
            return;
        }
        for (int i = start; i < word.length(); i ++) {
            string tmp = abbr;
            abbr += to_string(i - start + 1);
            if (i + 1 == word.length()) {
                abbrs.push_back(abbr);
            }
            for (int j = i + 1; j < word.length(); j ++) {
                string tmp2 = abbr;
                abbr += word.substr(i + 1, j - i - 1 + 1);
                _bt(j + 1, word, abbr, abbrs);
                abbr = tmp2;
            }
            abbr = tmp;
        }
    }
public:
    vector<string> generateAbbreviations(string word) {
        string abbr = "";
        vector<string> abbrs;
        for (int i = 0; i <= word.length(); i ++) {
            abbr = word.substr(0, i);
            _bt(i, word, abbr, abbrs);
            abbr = "";
        }
        return abbrs;
    }
};

class Solution {
private:
    void _bt(string& abbr, int start, vector<string>& abbrs) {
        while (start < abbr.length()) {
            int end = start;
            while (end < abbr.length()) {
                string left = abbr.substr(0, start);
                string right = abbr.substr(end + 1);
                string number = to_string(end - start + 1);
                //skip one char
                int newstart = start + number.length() + 1;
                string newabbr = abbr.substr(0, start) + number + abbr.substr(end + 1);
                abbrs.push_back(newabbr);
                _bt(newabbr, newstart, abbrs);
                end ++;
            }
            start ++;
        }
    }
public:
    vector<string> generateAbbreviations(string word) {
        string abbr = "";
        vector<string> abbrs;
        abbrs.push_back(word);
        _bt(word, 0, abbrs);
        return abbrs;
    }
};
