class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++) {
            m[words[i]] = i;
        }
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++) {
            string w = words[i];
            int len = w.length();
            for (int j = 0; j <= len; j ++) {
                string side = "";
                string rev_side = "";
                
                string mid = w.substr(0, j);
                string rev_mid = mid;
                reverse(rev_mid.begin(), rev_mid.end());
                if (rev_mid == mid) {
                    side = w.substr(j);
                    rev_side = side;
                    reverse(rev_side.begin(), rev_side.end());
                    if (m.count(rev_side) && m[rev_side] != i) {
                        res.push_back({m[rev_side], i});
                    }
                }
                // whole word reverse would make duplicate answers
                if (j == 0) {
                    continue;
                }
                mid = w.substr(len - j);
                rev_mid = mid;
                reverse(rev_mid.begin(), rev_mid.end());
                if (rev_mid == mid) {
                    side = w.substr(0, len - j);
                    rev_side = side;
                    reverse(rev_side.begin(), rev_side.end());
                    if (m.count(rev_side) && m[rev_side] != i) {
                        res.push_back({i, m[rev_side]});
                    }
                }
            }
        }
        return res;
    }
};
