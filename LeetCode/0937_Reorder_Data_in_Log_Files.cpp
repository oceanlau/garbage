class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits;
        vector<pair<string, string>> letters;
        for (const string& log : logs) {
            int i = log.find(' ');
            if (isdigit(log[i+1])) {
                digits.push_back(log);
            } else {
                letters.emplace_back(log.substr(0, i), log.substr(i+1));
            }
        }
        sort(letters.begin(), letters.end(), [](const pair<string, string>& l, const pair<string, string>& r){
            if (l.second == r.second) {
                return l.first < r.first;
            } else {
                return l.second < r.second;
            }
        });
        vector<string> res;
        for(const pair<string, string>& p : letters) {
            res.push_back(p.first + " " + p.second);
        }
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};
