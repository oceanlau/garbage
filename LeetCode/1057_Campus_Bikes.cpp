class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int, int>>> bucket(2000, vector<pair<int, int>> {});
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                bucket[abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])].emplace_back(i, j);
            }
        }
        vector<int> ans(workers.size(), -1);
        int workers_cnt = workers.size();
        vector<bool> bikes_available(bikes.size(), true);
        for (int i = 0; i < bucket.size(); i++) {
            for (const pair<int, int> p : bucket[i]) {
                if (ans[p.first] == -1 && bikes_available[p.second]) {
                    ans[p.first] = p.second;
                    bikes_available[p.second] = false;
                    if (--workers_cnt == 0) {
                        break;
                    }
                }
                if (workers_cnt == 0) {
                    break;
                }
            }
        }
        return ans;
    }
};
