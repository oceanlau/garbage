class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> char_freq;
        for (const char c : s) {
            char_freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (const auto& p : char_freq) {
            pq.emplace(p.second, p.first);
        }
        vector<pair<int, char>> cannotuse;
        string res;
        while (pq.size() != 0) {
            pair<int, char> cnt_char = pq.top();
            pq.pop();
            res += cnt_char.second;
            /* // even empty cnt_char needed in cannotuse, in order to calculate size()
            if (--cnt_char.first > 0) {
                cannotuse.push_back(make_pair(cnt_char.first, cnt_char.second));
            }
            */
            cannotuse.push_back(make_pair(--cnt_char.first, cnt_char.second));
            
            if (cannotuse.size() < k) {
                continue;
            }
            for (const pair<int, char> cnt_char : cannotuse) {
                if (cnt_char.first > 0) { // filter zero cnt here
                    pq.emplace(cnt_char.first, cnt_char.second);
                }
            }
            cannotuse.clear();
        }
        return res.length() == s.length() ? res : "";
    }
};
