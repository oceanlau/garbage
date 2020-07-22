class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<vector<int>> results;
        queue<vector<int>> paths;
        paths.push({0});
        while (!paths.empty()) {
            vector<int> path = paths.front();
            paths.pop();
            if (path.back() == target) {
                results.push_back(path);
            } else {
                for (const int next_node : graph[path.back()]) {
                    path.push_back(next_node);
                    paths.push(path);
                    path.pop_back();
                }
            }
        }
        return results;
    }
};

class Solution {
private:
    void _dfs(int cur, vector<vector<int>>& graph, vector<int>& solution, vector<vector<int>>& solutions) {
        solution.push_back(cur);
        if (cur == graph.size() - 1) {
            solutions.push_back(solution);
            solution.pop_back();
            return;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            _dfs(graph[cur][i], graph, solution, solutions);
        }
        solution.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> solutions;
        vector<int> solution;
        _dfs(0, graph, solution, solutions);
        return solutions;
    }
};
