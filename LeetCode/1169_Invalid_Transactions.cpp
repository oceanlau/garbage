struct Transaction {
    string name;
    int time;
    int amount;
    string city;
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        // within the 60 min time window
        deque<Transaction*> window;
        // name -> {city -> [Transaction*, ...], ...}
        unordered_map<string, unordered_map<string, deque<Transaction*>>> m;
        unordered_set<Transaction*> invalids;
        vector<Transaction> trans_list;
        for (const string& s : transactions) {
            stringstream ss(s);
            string seg = "";
            Transaction trans;
            getline(ss, seg, ',');
            trans.name = seg;
            getline(ss, seg, ',');
            trans.time = stoi(seg);
            getline(ss, seg, ',');
            trans.amount = stoi(seg);
            getline(ss, seg, ',');
            trans.city = seg;
            trans_list.push_back(trans);
        }
        auto comp = [](const Transaction& l, const Transaction& r) {
            return l.time < r.time;
        };
        sort(trans_list.begin(), trans_list.end(), comp);
        for (Transaction& t : trans_list) {
            while (!window.empty() && window.front()->time < t.time - 60) {
                Transaction* to_pop = window.front();
                m[to_pop->name][to_pop->city].pop_front();
                window.pop_front();
            }
            if (t.amount > 1000) {
                invalids.insert(&t);
            }
            for (const auto p : m[t.name]) {
                if (p.first != t.city) {
                    for (auto it = p.second.begin(); it != p.second.end(); it ++) {
                        invalids.insert(*it);
                    }
                    // careful
                    if (!p.second.empty()) {
                        invalids.insert(&t);
                    }
                }
            }
            window.push_back(&t);
            m[t.name][t.city].push_back(&t);
        }
        vector<string> res;
        for (auto it = invalids.begin(); it != invalids.end(); it ++) {
            res.push_back((*it)->name + ',' + to_string((*it)->time) + ',' + to_string((*it)->amount) + ',' + (*it)->city);
        }
        return res;
    }
};
