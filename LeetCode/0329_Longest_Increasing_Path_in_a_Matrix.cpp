//DFS+memo 60% 72%
class Solution {
private:
    vector<vector<int>> _dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int _dfs(vector<vector<int>>& matrix, int i, int j, int h, int w, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        for (const vector<int>& dir : _dirs) {
            if (i + dir[0] >= 0 && i + dir[0] < h && j + dir[1] >= 0 && j + dir[1] < w && matrix[i+dir[0]][j+dir[1]] > matrix[i][j]) {
                memo[i][j] = max(memo[i][j], _dfs(matrix, i+dir[0], j+dir[1], h, w, memo) + 1);
            }
        }
        if (memo[i][j] == 0) {
            memo[i][j] = 1;
        }
        return memo[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h == 0) {
            return 0;
        }
        int w = matrix[0].size();
        int longest = 0;
        vector<vector<int>> memo(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                longest = max(longest,_dfs(matrix, i, j, h, w, memo));
            }
        }
        return longest;
    }
};

//topological sort 35% 27%
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h == 0) {
            return 0;
        }
        int w = matrix[0].size();
        vector<vector<int>> dirs {{0,-1},{0,1},{-1,0},{1,0}};
        vector<vector<int>> indegrees(h, vector<int> (w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (const vector<int>& dir : dirs) {
                    if (i + dir[0] >= 0 && i + dir[0] < h && j + dir[1] >= 0 && j + dir[1] < w) {
                        if (matrix[i + dir[0]][j + dir[1]] < matrix[i][j]) {
                            indegrees[i][j]++;
                        }
                    }
                }
            }
        }
        
        queue<vector<int>> q;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (indegrees[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        
        int distance = 0;
        while(q.size() != 0) {
            distance ++;
            int q_size = q.size();
            while (q_size > 0) {
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();
                for (const vector<int>& dir : dirs) {
                    if (i + dir[0] >= 0 && i + dir[0] < h && j + dir[1] >= 0 && j + dir[1] < w) {
                        if (matrix[i + dir[0]][j + dir[1]] > matrix[i][j]) {
                            if (--indegrees[i + dir[0]][j + dir[1]] == 0) {
                                q.push({i + dir[0], j + dir[1]});
                            }
                        }
                    }
                }
                q_size --;
            }
        }
        
        return distance;
        
    }
};
