class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto comp = [](const vector<int>& l, const vector<int>& r) {
            return l[0] - l[1] < r[0] - r[1]; // send it to l city, saves more
        };
        sort(costs.begin(), costs.end(), comp);
        int cost = 0;
        int n = costs.size() / 2;
        for (int i = 0; i < n; i ++) {
            cost += costs[i][0];
        }
        for (int i = n; i < 2 * n; i ++) {
            cost += costs[i][1];
        }
        return cost;
    }
};
