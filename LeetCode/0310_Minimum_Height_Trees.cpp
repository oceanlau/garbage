class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> neighbors_cnt(n, 0);
        vector<vector<int>> edge_map(n, vector<int>{});
        for (const vector<int>& edge : edges) {
            neighbors_cnt[edge[0]] ++;
            neighbors_cnt[edge[1]] ++;
            edge_map[edge[0]].push_back(edge[1]);
            edge_map[edge[1]].push_back(edge[0]);
        }
        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            // ==0 只有一个node的特殊case
            if (neighbors_cnt[i] <= 1) {
                leaves.push(i);
            }
        }
        int remaining_cnt = n;
        while (remaining_cnt > 2) {
            int cur_leaves_cnt = leaves.size();
            while (cur_leaves_cnt > 0) {
                int node = leaves.front();
                leaves.pop();
                for (const int& neighbor : edge_map[node]) {
                    //可能最后被减成了0，但是1的时候加一次就好
                    if (--neighbors_cnt[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
                remaining_cnt--;
                cur_leaves_cnt --;
            }
        }
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};
