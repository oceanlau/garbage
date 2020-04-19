class Solution {
private:
    void _bt(int n, string sbg, vector<string>& sbgs) {
        if (n == 0) {
            //care fule
            if (sbg.length() > 0 && (sbg[0] != '0' || sbg.length() == 1) ) {
                sbgs.push_back(sbg);
            }
            return;
        }
        n -= 2;
        _bt(n, "0" + sbg + "0", sbgs);
        _bt(n, "1" + sbg + "1", sbgs);
        _bt(n, "8" + sbg + "8", sbgs);
        _bt(n, "6" + sbg + "9", sbgs);
        _bt(n, "9" + sbg + "6", sbgs);
    }
public:
    vector<string> findStrobogrammatic(int n) {
        string sbg = "";
        vector<string> sbgs;
        if (n % 2 == 1) {
            n -= 1;
            _bt(n, "0", sbgs);
            _bt(n, "1", sbgs);
            _bt(n, "8", sbgs);
        } else {
            _bt(n, sbg, sbgs);
        }
        return sbgs;
    }
};
