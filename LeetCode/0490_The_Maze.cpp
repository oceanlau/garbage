class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // find all possible des? dfs or bfs
        int h = maze.size();
        int w = maze[0].size();
        // for des, if no wall or two oppo wall, no path - useless
        bool topwall = destination[0] == 0 || maze[destination[0] - 1][destination[1]] == 1;
        bool btmwall = destination[0] == h-1 || maze[destination[0] + 1][destination[1]] == 1;
        bool leftwall = destination[1] == 0 || maze[destination[0]][destination[1] - 1] == 1;
        bool rightwall = destination[1] == w-1 || maze[destination[0]][destination[1] + 1] == 1;
        if (topwall && btmwall && !(leftwall || rightwall)) {
            return false;
        }
        if (leftwall && rightwall && !(topwall || btmwall)) {
            return false;
        }
        queue<pair<int, int>> q;
        q.push(make_pair(start[0], start[1]));
        unordered_set<string> visited;
        visited.insert(to_string(start[0]) + "_" + to_string(start[1]));
        vector<pair<int, int>> dirs {{0,1}, {1,0}, {-1,0}, {0,-1}};
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size != 0) {
                pair<int, int> start_pos = q.front();
                q.pop();
                for (int i = 0; i < dirs.size(); i++) {
                    pair<int, int> cur = start_pos;
                    while (cur.first >= 0 && cur.first < h && cur.second >= 0 && cur.second < w && maze[cur.first][cur.second] != 1) {
                        cur.first += dirs[i].first;
                        cur.second += dirs[i].second;
                    }
                    cur.first -= dirs[i].first;
                    cur.second -= dirs[i].second;
                    if (cur.first == destination[0] && cur.second == destination[1]) {
                        return true;
                    }
                    string cur_pos = to_string(cur.first) + "_" + to_string(cur.second);
                    if (!visited.count(cur_pos)) {
                        visited.insert(cur_pos);
                        q.push(make_pair(cur.first, cur.second));
                    }
                }
                q_size --;
            }
        }
        return false;
        
    }
};
