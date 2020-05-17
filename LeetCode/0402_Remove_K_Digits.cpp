class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (const char c : num) {
            while (res.length() > 0 && res.back() > c && k > 0) {
                res.pop_back();
                k --;
            }
            if (c != '0' || res.length() > 0) {
                res.push_back(c);
            }
        }
        while (res.length() > 0 && k > 0) {
            res.pop_back();
            k --;
        }
        return res.length() == 0 ? "0" : res;
    }
};
