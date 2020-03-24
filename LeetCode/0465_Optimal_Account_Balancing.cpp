class Solution {
private:
    // min trans required to clear debts[i,...]
    int _bt(vector<int>& debts, int i) {
        if (i == debts.size()) {
            return 0;
        }
        // important! must do it here! otherwise all logic below is invalid
        // also, last one of debts in the deepest recursion, must be zero
        while (i < debts.size() && debts[i] == 0) {
            i++;
        }
        if (i == debts.size()) {
            return 0;
        }
        int min_trans = INT_MAX;
        for (int j = i + 1; j < debts.size(); j++) {
            // only transfer to other type of person, may save 1 transfer, and don't get tle
            if ((debts[i] > 0 && debts[j] > 0) || (debts[i] < 0 && debts[j] < 0)) {
                continue;
            }
            //transfer debts, 1 trans
            debts[j] += debts[i];
            min_trans = min(min_trans, 1+_bt(debts, i+1));
            debts[j] -= debts[i];
        }
        return min_trans;
    }
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> debts_m;
        for (const auto& t : transactions) {
            debts_m[t[0]] -= t[2];
            debts_m[t[1]] += t[2];
        }
        vector<int> debts;
        for (const auto& d : debts_m) {
            if (d.second != 0) {
                debts.push_back(d.second);
            }
        }
        return _bt(debts, 0);
    }
};
