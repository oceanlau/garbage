//95% 100%
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //edges map(or vector) from parents
        vector<vector<int>> edges(numCourses, vector<int>{});
        //at the same time, a indegrees map(or vector) from parents
        vector<int> indegrees(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i ++) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }
        //find the ones parent with zero indegree, put in the result vec and into a queue
        queue<int> todo;
        for (int i = 0; i < indegrees.size(); i ++) {
            if (indegrees[i] == 0) {
                todo.push(i);
            }
        }
        vector<int> res {};
        if (todo.size() == 0) {
            return res;
        }
        //for each item in queue, reduce the children indegree
        //push all zero indegree child in the result vec and into the queue
        while (todo.size() != 0) {
            int course = todo.front();
            todo.pop();
            res.push_back(course);
            for (int i = 0; i < edges[course].size(); i++) {
                //It is not supposed to be less than zero! Don't worry!!
                if (--indegrees[edges[course][i]] == 0) {
                    todo.push(edges[course][i]);
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        }
        return vector<int> {};
    }
};
