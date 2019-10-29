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
