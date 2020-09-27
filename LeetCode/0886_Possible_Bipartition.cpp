class Solution {
private:
    bool _dfs(vector<vector<int>>& edge, int cur, vector<int>& labels, int label) {
        labels[cur] = label;
        label = -label;
        for (const int i : edge[cur]) {
            if (labels[i] == 0) {
                if (!_dfs(edge, i, labels, label)) {
                    return false;
                }
            } else if (labels[i] != label) {
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> labels(N + 1, 0);
        vector<vector<int>> edge (N + 1, vector<int> {});
        for (int i = 0; i < dislikes.size(); i++) {
            edge[dislikes[i][0]].push_back(dislikes[i][1]);
            edge[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for (int i = 0; i < N; i ++) {
            if (labels[i] == 0 && !_dfs(edge, i, labels, 1)) {
                return false;
            }
        }
        return true;
    }
};

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
