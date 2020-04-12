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
