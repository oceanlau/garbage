class Solution {
private:
    bool _dfs(vector<vector<int>>& graph, int cur, vector<int>& node_tag, int belong_to) {
        node_tag[cur] = belong_to;
        belong_to = -belong_to;
        for (const int next_node : graph[cur]) {
            if (node_tag[next_node] == 0) {
                if(!_dfs(graph, next_node, node_tag, belong_to)) {
                    return false;
                }
            } else if (node_tag[next_node] != belong_to) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size() < 2) {
            return true;
        }
        // 0 unvisited, 1 pos group, -1 neg group
        vector<int> node_tag(graph.size(), 0);
        //multiple graph, so start with each one
        for (int i = 0; i < node_tag.size(); i++) {
            if (node_tag[i] == 0) {
                if (!_dfs(graph, i, node_tag, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};
