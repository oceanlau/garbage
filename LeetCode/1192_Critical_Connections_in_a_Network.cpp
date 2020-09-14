class Solution {
private:
    void _dfs(int node, int parent, vector<int>& rank, int cur_rank, vector<int>& low, vector<vector<int>>& edges, vector<vector<int>>& critical) {
        rank[node] = cur_rank;
        low[node] = cur_rank;
        for (const int child : edges[node]) {
            if (child != parent) {
                if (rank[child] == -1) {
                    _dfs(child, node, rank, cur_rank + 1, low, edges, critical);
                    low[node] = min(low[node], low[child]);
                    if (low[child] > rank[node]) {
                        critical.push_back({node, child});
                    }
                } else {
                    low[node] = min(low[node], rank[child]);
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n, vector<int> {});
        for (const auto& conn : connections) {
            edges[conn[0]].push_back(conn[1]);
            edges[conn[1]].push_back(conn[0]);
        }
        vector<int> rank(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> critical;
        for (int node = 0; node < n; node ++) {
            if (rank[node] == -1) {
                _dfs(node, -1, rank, 0, low, edges, critical);
            }
        }
        return critical;
    }
};

class Solution {
private:
    // min rank found from cur node and its children
    int _dfs(int node, int depth, vector<vector<int>>& edges, vector<int>& rank, set<vector<int>>& res) {
        if (rank[node] >= 0) {
            return rank[node];
        }
        //set before dfs children
        rank[node] = depth;
        int min_depth = depth;
        for (const int neighbor : edges[node]) {
            // this is why init rank to -2, otherwise if we start from 0, every children is -1..
            if (rank[neighbor] == depth - 1) {
                continue;
            }
            int cur_depth = _dfs(neighbor, depth + 1, edges, rank, res);
            if (cur_depth <= depth) {
                res.erase({min(node, neighbor), max(node, neighbor)});
            }
            min_depth = min(min_depth, cur_depth);
        }
        //real rank, actually not needed, we use returned min_depth to erase elements
        //rank[node] = min_depth;
        return min_depth;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // min rank found from cur node and its children
        vector<int> rank(n, -2);
        vector<vector<int>> edges(n, vector<int> {});
        //set, for quick removal
        set<vector<int>> res;
        for (vector<int>& conn : connections) {
            if (conn[0] > conn[1]) {
                swap(conn[0], conn[1]);
            }
            edges[conn[0]].push_back(conn[1]);
            edges[conn[1]].push_back(conn[0]);
            res.insert({conn[0], conn[1]});
        }
        _dfs(0, 0, edges, rank, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
};
