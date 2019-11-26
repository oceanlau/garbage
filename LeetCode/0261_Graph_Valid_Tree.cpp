class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // a DFS should visit all nodes each exactly once
        vector<bool> visited(n, false);
        // all neighbors
        //unordered_map<int, vector<int>> graph;
        vector<vector<int>> graph (n, vector<int> {});
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        visited[0] = true;
        if(!_dfs(graph, 0, -1, visited)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool _dfs (vector<vector<int>>& graph, int node, int from, vector<bool>& visited) {
        for (const int neighbor : graph[node]) {
            //avoid going back
            if (neighbor == from) {
                continue;
            }
            if (visited[neighbor]) {
                return false;
            }
            visited[neighbor] = true;
            if (!_dfs(graph, neighbor, node, visited)) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, -1);
        for (const vector<int>& edge : edges) {
            int p0 = edge[0];
            int p1 = edge[1];
            while (parents[p0] != -1) {
                p0 = parents[p0];
            }
            while (parents[p1] != -1) {
                p1 = parents[p1];
            }
            if (p0 == p1) {
                return false;
            }
            parents[p0] = p1;
        }
        return edges.size() == n - 1;
    }
};

//wrong thinking. Consider [0,2][1,2]. Cant turn this into a directed graph
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // a DFS should visit all nodes each exactly once
        vector<bool> visited(n, false);
        // make it directed graph
        unordered_map<int, vector<int>> graph;
        for (vector<int>& edge : edges) {
            if (edge[0] > edge[1]) {
                swap(edge[0], edge[1]);
            }
            if (graph.find(edge[0]) == graph.end()) {
                graph[edge[0]] = vector<int> {edge[1]};
            } else {
                graph[edge[0]].push_back(edge[1]);
            }
        }
        
        visited[0] = true;
        if(!_dfs(graph, 0, visited)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool _dfs (unordered_map<int, vector<int>>& graph, int parent, vector<bool>& visited) {
        for (const int child : graph[parent]) {
            if (visited[child]) {
                return false;
            }
            visited[child] = true;
            if (!_dfs(graph, child, visited)) {
                return false;
            }
        }
        return true;
    }
};
