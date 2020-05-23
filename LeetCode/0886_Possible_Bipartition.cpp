class Solution {
private:
    bool _dfs(int N, int cur, int id, unordered_map<int, vector<int>>& edges, vector<int>& groups) {
        if (groups[cur] != 0) {
            return groups[cur] == id;
        }
        groups[cur] = id;
        for (const int node : edges[cur]) {
            if (!_dfs(N, node, -id, edges, groups)) {
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> edges;        
        for (const vector<int>& e : dislikes) {
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
        }
        vector<int> groups(N + 1, 0);
        for (const auto& e : edges) {
            if (groups[e.first] == 0) {
                // a unconnected graph
                if (!_dfs(N, e.first, 1, edges, groups)) {
                    return false;
                }
            }
        }
        return true;
    }
};
