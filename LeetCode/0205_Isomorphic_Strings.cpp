class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> m(256, -1);
        vector<bool> used(256, false);
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] != -1) {
                if ((char)m[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if (used[t[i]]) {
                    return false;
                }
                m[s[i]] = t[i];
                used[t[i]] = true;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m[256] = {0};
        bool used[256] = {false};
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 0 && used[t[i]] == false) {
                m[s[i]] = t[i] + 1;
                used[t[i]] = true;
            } else if (m[s[i]] != t[i] + 1) {
                return false;
            }
        }
        return true;
    }
};

// 51% 46%
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> transformer;
        vector<char> used_char;
        for (int i = 0; i != s.length(); i++) {
            if (transformer.find(s[i]) != transformer.end()) {
                if (transformer[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if (find(used_char.begin(), used_char.end(), t[i]) != used_char.end()) {
                    return false;
                }
                transformer[s[i]] = t[i];
                used_char.push_back(t[i]);
            }
        }
        return true;
    }
};
