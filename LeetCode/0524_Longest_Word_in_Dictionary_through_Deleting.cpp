class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for (int i = 0; i < d.size(); i++) {
            int j = 0;
            int k = 0;
            while (j < s.length()) {
                if (s[j] == d[i][k]) {
                    k++;
                }
                j++;
            }
            if (k == d[i].length()) {
                if (d[i].length() > ans.length() || (d[i].length() == ans.length() && d[i] < ans)) {
                    ans = d[i];
                }
            }
        }
        return ans;
    }
};
