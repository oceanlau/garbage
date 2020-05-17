class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length() == 0 || s.length() < k) {
            return 0;
        }
        vector<int> m(26, 0);
        for (const char c : s) {
            m[c - 'a'] ++;
        }
        int i = 0;
        bool flag = true;
        for (; i < 26; i++) {
            if (m[i] > 0 && m[i] < k) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return s.length();
        }
        stringstream ss(s);
        string part = "";
        int max_len = 0;
        char delim = 'a' + i;
        while (getline(ss, part, delim)) {
            max_len = max(max_len, longestSubstring(part, k));
        }
        return max_len;
    }
};

//bfs tle n^2
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length() == 0 || s.length() < k) {
            return 0;
        }
        vector<int> m (28, 0);
        for (const char c : s) {
            m[c - 'a'] ++;
        }
        m[27] = s.length() - 1;
        
        queue<vector<int>> q;
        q.push(m);
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt > 0) {
                m = q.front();
                q.pop();
                bool flag = true;
                for (int i = 0; i < 26; i++) {
                    if (m[i] > 0 && m[i] < k) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return m[27] - m[26] + 1;
                }
                if (m[27] - m[26] + 1 > k) {
                    int l = s[m[26]] - 'a';
                    int r = s[m[27]] - 'a';
                    m[l] --;
                    m[26] ++;
                    q.push(m);
                    m[l] ++;
                    m[r] --;
                    m[26] --;
                    m[27] --;
                    q.push(m);
                }
                cnt --;
            }
        }
        return 0;
        
    }
};
