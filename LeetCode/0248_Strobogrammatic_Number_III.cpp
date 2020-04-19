class Solution {
private:
    void _bt(string low, string high, int n, string sbg, vector<string>& sbgs) {
        if (n == 0) {
            if (sbg.length() > 0 && (sbg[0] != '0' || sbg.length() == 1) ) {
                // avoid int overflow
                if ((sbg.length() != low.length() || sbg >= low) &&
                    (sbg.length() != high.length() || sbg <= high)) {
                    sbgs.push_back(sbg);
                }
            }
            return;
        }
        n -= 2;
        _bt(low, high, n, "0" + sbg + "0", sbgs);
        _bt(low, high, n, "1" + sbg + "1", sbgs);
        _bt(low, high, n, "8" + sbg + "8", sbgs);
        _bt(low, high, n, "6" + sbg + "9", sbgs);
        _bt(low, high, n, "9" + sbg + "6", sbgs);
    }
public:
    int strobogrammaticInRange(string low, string high) {
        string sbg = "";
        vector<string> sbgs;
        int n = low.length();
        while (n <= high.length()) {
            if (n % 2 == 1) {
                _bt(low, high, n - 1, "0", sbgs);
                _bt(low, high, n - 1, "1", sbgs);
                _bt(low, high, n - 1, "8", sbgs);
            } else {
                _bt(low, high, n, sbg, sbgs);
            }
            n++;
        }
        return sbgs.size();
    }
};
