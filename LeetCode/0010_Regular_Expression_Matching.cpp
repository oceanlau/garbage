// recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        
        if (p.length() < 2) {
            if (s == p) {
                return true;
            } else if ("." == p && s.length() == 1) {
                return true;
            }
            return false;
        } else if ('*' == p[1]) {
            if (s.length() != 0 && (s[0] == p[0] || '.' == p[0])) {
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            }
            return isMatch(s, p.substr(2));
        } else {
            if (s.length() != 0 && (s[0] == p[0] || '.' == p[0])) {
                return isMatch(s.substr(1), p.substr(1));
            }
            return false;
        }
        
        
    }
};

// mistake, partial matching is not allowed
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
