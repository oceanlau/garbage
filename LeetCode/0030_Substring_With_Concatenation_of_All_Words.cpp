//too slow
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.length() == 0 || words.size() == 0) {
            return res;
        }
        int len = words[0].length();
        if (len == 0 || len > s.length()) {
            return res;
        }
        unordered_map<string, int> times;
        for (string & word : words) {
            times[word]++;
        }
        //s.length() - len + 1, plus 1 for s.length() == len
        for (int i = 0; i < s.length() - len + 1; i++) {
            int j = 0;
            unordered_map<string, int> count;
            while (j < words.size()) {
                string test = s.substr(i + j * len, len);
                if (times.find(test) == times.end()) {
                    break;
                } else if (++ count[test] > times[test]) {
                    break;
                }
                j ++;
            }
            if (j == words.size()) {
                res.push_back(i);
            }
        }
        return res;
    }
};
