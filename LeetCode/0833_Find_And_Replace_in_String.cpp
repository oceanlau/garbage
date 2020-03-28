class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<int, pair<int, string>, greater<int>> m;
        for (int i = 0; i < indexes.size(); i++) {
            if (S.compare(indexes[i], sources[i].length(), sources[i]) == 0) {
                m[indexes[i]] = make_pair(sources[i].length(), targets[i]);
            }
        }
        for (const auto& p : m) {
            S.replace(p.first, p.second.first, p.second.second);
        }
        return S;
    }
};
