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
