class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // careful!!
        if (k == 0) {
            return 0;
        }
        list<pair<char, int>> last_loc;
        unordered_map<char, list<pair<char, int>>::iterator> m;
        int maxlen = 0;
        int left = 0;
        for (int i = 0; i < s.length(); i++) {
            if (m.count(s[i])) {
                last_loc.splice(last_loc.end(), last_loc, m[s[i]]);
                m[s[i]]->second = i;
            } else {
                if (last_loc.size() == k) {
                    // careful!!
                    left = last_loc.front().second + 1;
                    m.erase(last_loc.front().first);
                    last_loc.pop_front();
                }
                last_loc.emplace_back(s[i], i);
                m[s[i]] = last_loc.end();
                m[s[i]] --;
            }
            maxlen = max(maxlen, i - left + 1);
        }
        return maxlen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        list<pair<char, int>> locs;
        unordered_map<char, list<pair<char, int>>::iterator> toLoc;
        int curStart = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (toLoc.count(s[i])) {
                toLoc[s[i]]->second = i;
                locs.splice(locs.end(), locs, toLoc[s[i]]);
            } else {
                locs.emplace_back(s[i], i);
                toLoc[s[i]] = locs.end();
                toLoc[s[i]] --;
                if (locs.size() > k) {
                    curStart = locs.front().second + 1;
                    toLoc.erase(locs.front().first);
                    locs.pop_front();
                }
            }
            maxLen = max(maxLen, i - curStart + 1);
        }
        return maxLen;
    }
};
