class Solution {
private:
    bool _dfs(vector<vector<int>>& edges, int i, vector<bool>& parents, vector<bool>& visited) {
        parents[i] = true;
        visited[i] = true;
        for (int j = 0; j < edges[i].size(); j++) {
            if (parents[edges[i][j]]) {
                return false;
            }
            if (visited[edges[i][j]]) {
                continue;
            }
            if (!_dfs(edges, edges[i][j], parents, visited)) {
                return false;
            }
        }
        parents[i] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // map of edges
        // visited vector to avoid duplicate check
        // do dfs on every unvisited node, set isyourparent[node] along the dfs path
        // if one edge points to isparent node, return false
        vector<vector<int>> edges(numCourses, vector<int> {});
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < edges.size(); i++) {
            if (visited[i] || edges[i].empty()) {
                visited[i] = true;
                continue;
            }
            vector<bool> parents(numCourses, false);
            if (!_dfs(edges, i, parents, visited)) {
                return false;
            }
        }
        return true;
    }
};

// Extra careful 86% 30.9%
class Solution {
private:
    bool _dfs(vector<vector<int>>& pointers, int i, vector<bool>& parents, vector<bool>& visited) {
        visited[i] = true;
        parents[i] = true;
        for(int j = 0; j < pointers[i].size(); j++) {
            if (parents[pointers[i][j]]) {
                return false;
            }
            if (visited[pointers[i][j]]) {
                continue;
            }
            if (!_dfs(pointers, pointers[i][j], parents, visited)) {
                return false;
            }
        }
        parents[i] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //from pairs to map
        vector<vector<int>> pointers(numCourses, vector<int>{});
        for (int i = 0; i < prerequisites.size(); i++) {
            pointers[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //visited map
        vector<bool> visited(numCourses, false);
        //for all unvisited courses, do dfs, if one course points back to its parents(unordered_set O(1) insert search delete, or vector)
        for (int i = 0; i < pointers.size(); i++) {
            if (visited[i] || pointers[i].size() == 0) {
                visited[i] = true;
                continue;
            }
            vector<bool> parents(numCourses, false);
            if (!_dfs(pointers, i, parents, visited)) {
                return false;
            }
        }
        return true;
    }
};
