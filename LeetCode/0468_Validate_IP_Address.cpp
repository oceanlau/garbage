class Solution {
private:
    bool isIPv4(string IP) {
        stringstream ss(IP);
        string seg;
        int cnt = 0;
        while (getline(ss, seg, '.')) {
            if (seg.length() == 0 || seg.length() > 3) {
                return false;
            } else if (seg.length() > 1 && seg[0] == '0'){
                return false;
            }
            int i = 0;
            for (const char c : seg) {
                if (!isdigit(c)) {
                    return false;
                }
                i = i * 10 + (c - '0');
            }
            if (i > 255) {
                return false;
            }
            if (++cnt > 4) {
                return false;
            }
        }
        if (cnt != 4) {
            return false;
        }
        if (IP[IP.length() - 1] == '.') {
            return false;
        }
        return true;
    }
    bool isIPv6(string IP) {
        stringstream ss(IP);
        string seg;
        int cnt = 0;
        while (getline(ss, seg, ':')) {
            if (seg.length() == 0 || seg.length() > 4) {
                return false;
            }
            for (const char c : seg) {
                if (isdigit(c)) {
                    continue;
                } else if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
                    continue;
                }
                return false;
            }
            if (++cnt > 8) {
                return false;
            }
        }
        if (cnt != 8) {
            return false;
        }
        if (IP[IP.length() - 1] == ':') {
            return false;
        }
        return true;
    }
public:
    string validIPAddress(string IP) {
        if (isIPv4(IP)) {
            return "IPv4";
        } else if (isIPv6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
};
