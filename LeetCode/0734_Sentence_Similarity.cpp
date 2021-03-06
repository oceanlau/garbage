class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, unordered_set<string>> m;
        for (const vector<string>& p : pairs) {
            m[p[0]].insert(p[1]);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && !m[words1[i]].count(words2[i]) && !m[words2[i]].count(words1[i])) {
                return false;
            }
        }
        return true;
    }
};
