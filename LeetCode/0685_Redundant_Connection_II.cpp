class Solution {
private:
    int _findroot(vector<int>& parent, int node) {
        while (parent[node] != -1) {
            node = parent[node];
        }
        return node;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // one more edge than usual, so edges.size() happens to be the node count
        // but because node start from 1, we need +1 space and 0 is not used
        vector<int> parent(edges.size() + 1, -1);
        vector<int> candidate1;
        vector<int> candidate2;
        for (int i = 0; i < edges.size(); i++) {
            if (parent[edges[i][1]] == -1) {
                parent[edges[i][1]] = edges[i][0];
            } else {
                candidate1 = edges[i];
                candidate2 = {parent[edges[i][1]], edges[i][1]};
                //set this edge invalid
                edges[i][0] = -1;
                edges[i][1] = -1;
            }
        }
        parent = vector<int>(edges.size() + 1, -1);
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == -1 && edges[i][1] == -1) {
                continue;
            }
            if (_findroot(parent, edges[i][0]) == edges[i][1]) {
                if (candidate1.empty() && candidate2.empty()) {
                    return edges[i];
                } else {
                    return candidate2;
                }
            }
            parent[edges[i][1]] = edges[i][0];
        }
        return candidate1;
    }
};
