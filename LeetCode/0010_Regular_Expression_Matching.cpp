// mistake
class Solution {
public:
    bool isMatch(string s, string p) {
        auto pit = p.begin();
        for (auto it = s.begin(); it != s.end(); it ++) {
            if (*it == *pit || '.' == *pit) {
                pit ++;
                continue;
            }
            if ('*' == *pit) {
                if (*it == *(pit - 1) || '.' == *(pit - 1)) {
                    continue;
                }
                if (*it == *(pit + 1)) {
                    pit += 2;
                    continue;
                }
            }
            return false;
        }
        if (pit + 1 != p.end()) {
            return false;
        }
        return true;
    }
};
