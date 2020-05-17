class Solution {
private:
    string norm(string s) {
        if (s.length() == 0) {
            return "_";
        }
        string result = "0";
        int diff = s[0] - 'a';
        for (int i = 1; i < s.length(); i++) {
            int cur = s[i] - 'a' - diff;
            if (cur < 0) {
                cur += 26;
            }
            result += '_' + to_string(cur);
        }
        return result;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strings) {
            groups[norm(s)].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto p : groups) {
            result.push_back(p.second);
        }
        return result;
    }
};
