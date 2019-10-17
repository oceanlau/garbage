// 77% 82%
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> counter(26, 0);
        for (const char c : s) {
            counter[c-'a'] ++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (counter[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// O(2n) 56% O(n) 34%
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counter;
        for (const char c : s) {
            counter[c] ++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (counter[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
