//double direction directed graph
// map(from_node) of map(to_node + weight)
class Solution {
private:
    double _dfs(unordered_map<string, unordered_map<string, double>>& graph, string from, string to, unordered_set<string>& visited) {
        if (graph.count(from) && from == to) {
            return 1;
        }
        double res = -1.0;
        for (const auto& edge : graph[from]) {
            if (visited.count(edge.first)) {
                continue;
            }
            visited.insert(edge.first);
            double child = _dfs(graph, edge.first, to, visited);
            if (child == -1) {
                visited.erase(edge.first);
                continue;
            }
            return edge.second * child;
        }
        return res;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            unordered_set<string> visited;
            res.push_back(_dfs(graph, queries[i][0], queries[i][1], visited));
        }
        return res;
    }
};
