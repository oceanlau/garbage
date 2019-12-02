class Solution {
public:
    string alienOrder(vector<string>& words) {
        //watch the edge cases
        if (words.size() == 0) {
            return "";
        }
        if (words.size() == 1) {
            return words[0];
        }
        unordered_map<char, vector<char>> edges;
        unordered_map<char, int> indegrees;
        for (int i = 0; i < words.size() - 1; i++) {
            bool has_found_relationship = false;
            for (int j = 0; j < max(words[i].length(), words[i+1].length()); j++) {
                if (j < words[i].length() && !indegrees.count(words[i][j])) {
                    indegrees[words[i][j]] = 0;
                }
                if (j < words[i+1].length() && !indegrees.count(words[i+1][j])) {
                    indegrees[words[i+1][j]] = 0;
                }
                if (!has_found_relationship && j < min(words[i].length(), words[i+1].length()) && words[i][j] != words[i+1][j]) {
                    edges[words[i][j]].push_back(words[i+1][j]);
                    indegrees[words[i+1][j]]++;
                    has_found_relationship = true;
                }
            }
        }
        
        stringstream res;
        queue<char> to_sort;
        for (const auto& kv : indegrees) {
            if (kv.second == 0) {
                to_sort.push(kv.first);
            }
        }
        
        while (!to_sort.empty()) {
            char cur = to_sort.front();
            to_sort.pop();
            for (int i = 0; i < edges[cur].size(); i++) {
                indegrees[edges[cur][i]] --;
                if (indegrees[edges[cur][i]] == 0) {
                    to_sort.push(edges[cur][i]);
                }
            }
            res << cur;
        }
        string result = res.str();
        if (result.length() != indegrees.size()) {
            return "";
        }
        return result;
        
    }
};
