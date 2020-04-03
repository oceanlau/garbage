class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int>> edges;
        unordered_map<int, int> indegrees;
        for (const vector<int>& seq : seqs) {
            for (int i = 0; i < seq.size(); i++) {
                //consider [1] [[1],[1],[1]]
                // mark all parents
                if (!indegrees.count(seq[i])) {
                    indegrees[seq[i]] = 0;
                }
                // for children
                if (i > 0) {
                    edges[seq[i-1]].push_back(seq[i]);
                    indegrees[seq[i]] ++;
                }
            }
        }
        queue<int> roots;
        for (const auto p : indegrees) {
            if (p.second == 0) {
                roots.push(p.first);
            }
        }
        int org_i = 0;
        while(!roots.empty()) {
            if (roots.size() > 1) {
                return false;
            }
            int root = roots.front();
            roots.pop();
            if (org_i >= org.size()) {
                return false;
            }
            if (org[org_i] != root) {
                return false;
            }
            org_i ++;
            if (edges.count(root)) {
                for (const int child : edges[root]) {
                    if (--indegrees[child] == 0) {
                        roots.push(child);
                    }
                }
                edges.erase(root);
            }
        }
        return org_i == org.size() && org_i == indegrees.size();
    }
};
