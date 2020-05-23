class Solution {
public:
    bool canCross(vector<int>& stones) {
        // for each stone, record a set of k that lands on it
        unordered_map<int, unordered_set<int>> ks;
        for (int i = 0; i < stones.size(); i ++) {
            ks[stones[i]] = {};
        }
        // first stone is always 0
        ks[0].insert(0);
        
        for (int i = 0; i < stones.size(); i ++) {
            for (auto it = ks[stones[i]].begin(); it != ks[stones[i]].end(); it++) {
                int k = *it;
                int reach = stones[i] + k;
                if (stones.back() >= reach - 1 && stones.back() <= reach + 1) {
                    return true;
                }
                if (k - 1 > 0 && ks.count(reach - 1)) {
                    ks[reach - 1].insert(k - 1);
                }
                if (k > 0 && ks.count(reach)) {
                    ks[reach].insert(k);
                }
                if (ks.count(reach + 1)) {
                    ks[reach + 1].insert(k + 1);
                }
            }
        }
        return false;
    }
};
