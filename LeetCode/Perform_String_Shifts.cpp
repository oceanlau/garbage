class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total = 0;
        for (const vector<int> s : shift) {
            if (s[0] == 0) {
                total -= s[1];
            } else {
                total += s[1];
            }
        }
        total %= (int)s.length();
        if (total < 0) {
            string left = s.substr(0, -total);
            string right = s.substr(-total);
            return right + left;
        } else {
            string left = s.substr(0, s.length() - total);
            string right = s.substr(s.length() - total);
            return right + left;
        }
        
    }
};
