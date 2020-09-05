class Solution {
private:
    bool _bt(unordered_map<string, vector<string>>& m, vector<string>& itinerary, string& start, int& len) {
        if (itinerary.size() == len) {
            return true;
        }
        if (!m.count(start)) {
            return false;
        }
        for (auto it = m[start].begin(); it != m[start].end(); it ++) {
            if (*it == "") {
                continue;
            }
            itinerary.push_back(*it);
            string dest = *it;
            *it = "";
            if (_bt(m, itinerary, dest, len)) {
                return true;
            }
            *it = dest;
            itinerary.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> m; 
        for (const vector<string>& ticket : tickets) {
            m[ticket[0]].push_back(ticket[1]);
        }
        for (auto& p : m) {
            sort(p.second.begin(), p.second.end());
        }
        string start = "JFK";
        vector<string> itinerary {start};
        int len = tickets.size() + 1;
        _bt(m, itinerary, start, len);
        return itinerary;
    }
};

class Solution {
private:
    bool _bt(unordered_map<string, list<string>>& m, string dep, vector<string>& itinerary, int total) {
        if (itinerary.size() == total) {
            return true;
        }
        for (auto it = m[dep].begin(); it != m[dep].end(); it++) {
            string des = *it;
            if (des == "") {
                continue;
            }
            itinerary.push_back(des);
            *it = "";
            if (_bt(m, des, itinerary, total)) {
                return true;
            }
            *it = des;
            itinerary.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, list<string>> m;
        for (const vector<string>& ticket : tickets) {
            m[ticket[0]].push_back(ticket[1]);
        }
        for (auto& p : m) {
            p.second.sort();
        }
        vector<string> itinerary {"JFK"};
        int total = tickets.size() + 1;
        _bt(m, "JFK", itinerary, total);
        return itinerary;
    }
};
