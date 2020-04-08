class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courses;
        unordered_map<int, vector<int>> edges;
        vector<int> indegrees(numCourses, 0);
        for (const vector<int>& prereq : prerequisites) {
            edges[prereq[0]].push_back(prereq[1]);
            indegrees[prereq[1]] ++;
        }
        queue<int> next;
        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                next.push(i);
            }
        }
        while (!next.empty()) {
            int nex = next.front();
            next.pop();
            courses.push_back(nex);
            for (const int dest : edges[nex]) {
                if (--indegrees[dest] == 0) {
                    next.push(dest);
                }
            }
        }
        if (courses.size() == numCourses) {
            reverse(courses.begin(), courses.end());
            return courses;
        }
        return {};
    }
};
