class Solution {
public:
    string nextClosestTime(string time) {
        set<char> digits;
        for (const char digit : time) {
            if (isdigit(digit)) {
                digits.insert(digit);
            }
        }
        char smallest = *(digits.begin());
        char d = time[4];
        auto it = digits.find(d);
        while (it != digits.end() && *it == d) {
            it ++;
        }
        if (it != digits.end()) {
            time[4] = *it;
            return time;
        }
        time[4] = smallest;
        
        d = time[3];
        it = digits.find(d);
        while (it != digits.end() && *it == d) {
            it ++;
        }
        if (it != digits.end() && *it <= '5') {
            time[3] = *it;
            return time;
        }
        time[3] = smallest;
        
        d = time[1];
        it = digits.find(d);
        while (it != digits.end() && *it == d) {
            it ++;
        }
        if (it != digits.end() && (time[0] < '2' || *it <= '4')) {
            time[1] = *it;
            return time;
        }
        time[1] = smallest;
        
        d = time[0];
        it = digits.find(d);
        while (it != digits.end() && *it == d) {
            it ++;
        }
        if (it != digits.end() && *it <= '2') {
            time[0] = *it;
            return time;
        }
        time[0] = smallest;
        
        return time;
    }
};

//rule based
class Solution {
public:
    string nextClosestTime(string time) {
        set<char> candidates;
        for (const char c : time) {
            if (c == ':') {
                continue;
            }
            candidates.insert(c);
        }
        auto it = candidates.find(time[4]);
        if (*it != *candidates.rbegin()) {
            it++;
            time[4] = *it;
            return time;
        }
        time[4] = *(candidates.begin());
        
        it = candidates.find(time[3]);
        if (*it != *candidates.rbegin()) {
            it++;
            if (*it < '6') {
                time[3] = *it;
                return time;
            }
        }
        time[3] = *(candidates.begin());
        
        it = candidates.find(time[1]);
        if (*it != *candidates.rbegin()) {
            it++;
            if (time[0] < '2' || *it < '4') {
                time[1] = *it;
                return time;
            }
        }
        time[1] = *(candidates.begin());
        
        it = candidates.find(time[0]);
        if (*it != *candidates.rbegin()) {
            it++;
            if (*it < '3') {
                time[0] = *it;
                return time;
            }
        }
        time[0] = *(candidates.begin());
        
        return time;
    }
};
