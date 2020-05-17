class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
        vector<string> m {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res {""};
        for (const char c : digits) {
            int i = c - '0';
            vector<string> cur {};
            for (const string& s : res) {
                for (const char c : m[i]) {
                    cur.push_back(s + c);
                }
            }
            res.swap(cur);
        }
        return res;
    }
};

class Solution {
private:
    vector<vector<char>> letter_map {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
public:    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) {
            return res;
        }
        vector<string> suffixes {""};
        if (digits.length() > 1) {
            suffixes = letterCombinations(digits.substr(1));
        }
        vector<char> letters = letter_map[digits[0] - '2'];
        for (char& c : letters) {
            for (string& suffix : suffixes) {
                res.push_back(c + suffix);
            }
        }
        return res;
    }
};
