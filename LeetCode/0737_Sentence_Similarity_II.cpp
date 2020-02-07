//naive union find
class Solution {
private:
    unordered_map<string, string> _parent;
    void _union(string w1, string w2) {
        w1 = _find(w1);
        w2 = _find(w2);
        if (w1 != w2) {
            _parent[w1] = w2;
        }
    }
    string _find(string w) {
        while (_parent.count(w)){
            w = _parent[w];
        }
        return w;
    }
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        for (const vector<string>& p : pairs) {
            _union(p[0], p[1]);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && _find(words1[i]) != _find(words2[i])) {
                return false;
            }
        }
        return true;
    }
};
