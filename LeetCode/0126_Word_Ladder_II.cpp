class Solution {
private:
    // dfs backtrack ladder safe to pass by ref!
    void _dfs(unordered_map<string, vector<string>>& edges, string src, string& des, vector<string>& ladder, vector<vector<string>>& ladders) {
        if (src == des) {
            vector<string> rev_ladder = ladder;
            reverse(rev_ladder.begin(), rev_ladder.end());
            ladders.push_back(rev_ladder);
            return;
        }
        for (const string& d : edges[src]) {
            ladder.push_back(d);
            _dfs(edges, d, des, ladder, ladders);
            ladder.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //BFS to record all edges
        unordered_map<string, vector<string>> edges;//des to src
        queue<string> q;
        unordered_set<string> candidates(wordList.begin(), wordList.end());
        if (!candidates.count(endWord)) {
            return {};
        }
        candidates.erase(beginWord);
        q.push(beginWord);
        while (!q.empty()) {
            int lvl_cnt = q.size();
            unordered_set<string> unvisited = candidates;
            while (lvl_cnt) {
                string src = q.front();
                q.pop();
                for (int i = 0; i < src.length(); i++) {
                    for (char c = 'a'; c < 'z'; c++) {
                        string des = src;
                        des[i] = c;
                        if (unvisited.count(des)) {
                            // want to records all edges
                            edges[des].push_back(src);
                            if (candidates.count(des)) {
                                // but dont want to recalculate in the queue
                                q.push(des);
                                candidates.erase(des);
                            }
                        }
                    }
                }
                lvl_cnt --;
            }
            if (!candidates.count(endWord)) {
                break;
            }
        }
        
        //DFS to find all paths from des to src
        vector<vector<string>> ladders;
        vector<string> ladder {endWord};
        _dfs(edges, endWord, beginWord, ladder, ladders);
        return ladders;
    }
};

class Solution {
private:
    void _dfs(string target, string cur_word, unordered_map<string, vector<string>>& graph, vector<string>& cur, vector<vector<string>>& res) {
        if (cur.back() == target) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < graph[cur_word].size(); i++) {
            cur.push_back(graph[cur_word][i]);
            _dfs(target, graph[cur_word][i], graph, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // BFS to find the shortest distance to target, and build a graph
        // BFS, so no loop, also make sure it is shortest (early stopping)
        // try each char at every BFS step
        
        // reverse DFS using the graph, the find the path
        unordered_set<string> candidates(wordList.begin(), wordList.end());//O(n)
        if (!candidates.count(endWord)) {
            return {};
        }
        queue<string> nodes;
        nodes.push(beginWord);
        unordered_map<string, vector<string>> graph;
        bool has_found = false;
        // O(n)
        while (!has_found && !nodes.empty()) {
            int nodes_size = nodes.size();
            // Careful! Current node should only build graph with unvisited words
            unordered_set<string> unvisited = candidates;
            while (nodes_size > 0) {
                string candidate = nodes.front();
                if (candidate == endWord) {
                    has_found = true;
                }
                nodes.pop();
                if (!has_found) {
                    // build graph of next level
                    for (int i = 0; i < candidate.length(); i++) { // O(str_len)
                        string tmp = candidate;
                        char c = 'a';
                        while (c <= 'z') { //O(26)
                            tmp[i] = c;
                            // Careful here. Compared to word ladder I, we try to find all paths.
                            // Thus when two or more different candidates lead to the same word. We need to record all!
                            if (unvisited.count(tmp)) {
                                graph[tmp].push_back(candidate);
                            }
                            //delete to avoid loop in queue
                            if (candidates.count(tmp)) {
                                nodes.push(tmp);
                                candidates.erase(tmp);
                            }
                            c ++;
                        }
                    }
                }
                nodes_size --;
            }
        }
        if (!has_found) {
            return {};
        }
        // dfs O(n)
        vector<vector<string>> res;
        vector<string> cur {endWord};
        _dfs(beginWord, endWord, graph, cur, res);
        for (int i = 0; i < res.size(); i++) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
