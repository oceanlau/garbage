class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<pair<int, int>>> waitlists(26, vector<pair<int, int>> {}); // pair i, j means word i waits at its char j
        for (int i = 0; i < words.size(); i++) {
            waitlists[words[i][0]-'a'].emplace_back(i, 0);
        }
        int ans = 0;
        for (const char c : S) {
            vector<pair<int, int>> waitlist = waitlists[c - 'a'];
            waitlists[c - 'a'].clear();
            for (int i = waitlist.size() - 1; i >= 0; i--) {
                pair<int, int> cur = waitlist[i];
                if (cur.second + 1 == words[cur.first].length()) {
                    ans ++;
                } else {
                    cur.second ++;
                    waitlists[words[cur.first][cur.second] - 'a'].push_back(cur);
                }
            }
        }
        return ans;
    }
};
