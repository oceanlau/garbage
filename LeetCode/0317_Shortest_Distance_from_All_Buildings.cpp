class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        
        // need at least two maps, one to prevent going back at every dfs (naively, create one for every bfs, smartly use a global one with decreasing canvisit value). one to record sum dists
        // grid could serve as one of them
        
        // create a sumdistsmap and canvisit value init 0
        // do a bfs from every building (if num of building is smaller)
        //     only go to points where previous buildings can reach, if surrounded by cannotvisit pos, that means this building does not share starting loc with other buildings, give up return -1 // this is a super interesting oberservation, need proof!
        //     sum to a sumdists map
        //     in the last round, find min sum dist! (tricky here, dont need a second sweep)
        int h = grid.size();
        int w = grid[0].size();
        auto sumdists = grid;
        int min_sumdist = INT_MAX;
        int canvisit = 0;
        vector<pair<int, int>> dirs {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    min_sumdist = INT_MAX;// reset, only uses last round value
                    queue<pair<int, int>> tovisit;
                    tovisit.emplace(i, j);
                    int dist = 1;
                    while (tovisit.size() != 0) {
                        int q_size = tovisit.size();
                        while (q_size != 0) {
                            pair<int, int> cur = tovisit.front();
                            tovisit.pop();
                            bool at_least_one_path = false;
                            for (int d = 0; d < dirs.size(); d++) {
                                int y = cur.first + dirs[d].first;
                                int x = cur.second + dirs[d].second;
                                if (y >= 0 && y < h && x >= 0 && x < w && grid[y][x] == canvisit) {
                                    at_least_one_path = true;
                                    grid[y][x] --; // mark as visited
                                    sumdists[y][x] += dist;
                                    if (min_sumdist > sumdists[y][x]) {
                                        min_sumdist = sumdists[y][x];
                                    }
                                    tovisit.emplace(y, x);
                                }
                            }
                            // **a building** surounded by cannot reach pos
                            if (grid[cur.first][cur.second] == 1 && !at_least_one_path) {
                                return -1;
                            }
                            q_size --;
                        }
                        dist ++;
                    }
                    canvisit--;
                }
            }
        }
        return min_sumdist;
    }
};
