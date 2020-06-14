class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counter;
        vector<vector<char>> bucket(s.length() + 1, vector<char>{});
        for (const char c : s) {
            counter[c] ++;
        }
        for (const auto t : counter) {
            bucket[t.second].push_back(t.first);
        }
        stringstream res;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (const char c : bucket[i]) {
                res << string(i, c);
            }
        }
        return res.str();
    }
};
