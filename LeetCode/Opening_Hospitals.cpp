#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// dp[parent][0] (no hospital and its own parent has no hospital)
//   -> min(sums of all combination of dp[child][0/2] with at least one child at state 2)
// dp[parent][1] (no hospital but parent has hospital)
//   -> min(sums of all combination of dp[child][0/2])
// dp[parent][2] (with hospital)
//   -> 1 + min(sums of all combination of dp[child][1/2])
int get_dp(vector<vector<int>>& dp, int city, int stat, int n, unordered_map<int, unordered_set<int>>& edges, unordered_set<int>& visited) {
    if (dp[city][stat] != n) {
        return dp[city][stat];
    }
    visited.insert(city);
    if (stat == 0 || stat == 1) {
        int min_sum = 0;
        // If no child, this n + 1 would invalidate stat 0 
        int min_inc = n + 1;
        for (auto it = edges[city].begin(); it != edges[city].end(); it ++){
            if (visited.count(*it)) {
                continue;
            }
            int child0 = get_dp(dp, *it, 0, n, edges, visited);
            int child2 = get_dp(dp, *it, 2, n, edges, visited);
            min_sum += min(child0, child2);
            min_inc = min(min_inc, child2 - child0);
        }
        if (stat == 0 && min_inc > 0) {
            min_sum += min_inc;
        }
        dp[city][stat] = min_sum;
    } else {
        int min_sum = 0;
        for (auto it = edges[city].begin(); it != edges[city].end(); it ++){
            if (visited.count(*it)) {
                continue;
            }
            int child1 = get_dp(dp, *it, 1, n, edges, visited);
            int child2 = get_dp(dp, *it, 2, n, edges, visited);
            min_sum += min(child1, child2);
        }
        dp[city][stat] = 1 + min_sum;
    }
    visited.erase(city);
    //cout << "city: " << city + 1 << ", stat: " << stat << ", dp: " << dp[city][stat] << endl;
    return dp[city][stat];
};

int min_hospitals(int n, vector<int>& city_from, vector<int>& city_to) {
    unordered_map<int, unordered_set<int>> edges;
    for (int i = 0; i < city_from.size(); i++) {
        edges[city_from[i] - 1].insert(city_to[i] - 1);
        edges[city_to[i] - 1].insert(city_from[i] - 1);
    }
    vector<vector<int>> dp(n, vector<int> (3, n));
    unordered_set<int> visited;
    return min(get_dp(dp, 0, 0, n, edges, visited), get_dp(dp, 0, 2, n, edges, visited));
};

int main() {
    vector<int> f1 {1, 3, 1, 3, 2, 1};
    vector<int> t1 {2, 6, 4, 7, 5, 3};
    cout << min_hospitals(7, f1, t1) << endl;

    vector<int> f2 {4, 1, 2, 3};
    vector<int> t2 {3, 2, 3, 4};
    cout << min_hospitals(4, f2, t2) << endl;

    vector<int> f3 {1, 1, 6, 1, 1, 2, 11, 12, 4, 12, 6};
    vector<int> t3 {11, 2, 7, 6, 12, 3, 10, 9, 5, 8, 4};
    cout << min_hospitals(12, f3, t3) << endl;
};
