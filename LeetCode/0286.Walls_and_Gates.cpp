//13% 40% Code simplified. Slow because of too much vector construction?
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) {
            return;
        }
        int n = rooms[0].size();
        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push(vector<int> {i, j});
                }
            }
        }
        
        while (q.size() != 0) {
            vector<int> p = q.front();
            q.pop();
            //distance precheck prevent infinite loop!
            if (p[0] > 0 && rooms[p[0]-1][p[1]] > 0 && rooms[p[0]-1][p[1]] > rooms[p[0]][p[1]] + 1) {
                rooms[p[0]-1][p[1]] = rooms[p[0]][p[1]] + 1;
                q.push(vector<int> {p[0]-1, p[1]});
            }
            if (p[0] < m - 1 && rooms[p[0]+1][p[1]] > 0 && rooms[p[0]+1][p[1]] > rooms[p[0]][p[1]] + 1) {
                rooms[p[0]+1][p[1]] = rooms[p[0]][p[1]] + 1;
                q.push(vector<int> {p[0]+1, p[1]});
            }
            if (p[1] > 0 && rooms[p[0]][p[1]-1] > 0 && rooms[p[0]][p[1]-1] > rooms[p[0]][p[1]] + 1) {
                rooms[p[0]][p[1]-1] = rooms[p[0]][p[1]] + 1;
                q.push(vector<int> {p[0], p[1]-1});
            }
            if (p[1] < n - 1 && rooms[p[0]][p[1]+1] > 0 && rooms[p[0]][p[1]+1] > rooms[p[0]][p[1]] + 1) {
                rooms[p[0]][p[1]+1] = rooms[p[0]][p[1]] + 1;
                q.push(vector<int> {p[0], p[1]+1});
            }
        }
    }
};

//11% 10%
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) {
            return;
        }
        int n = rooms[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    queue<vector<int>> q;
                    q.push(vector<int> {i, j});
                    int distance = 0;
                    while (q.size() != 0) {
                        int q_size = q.size();
                        while (q_size > 0) {
                            vector<int> p = q.front();
                            q.pop();
                            rooms[p[0]][p[1]] = distance;
                            //distance precheck prevent infinite loop!
                            if (p[0] > 0 && rooms[p[0]-1][p[1]] > 0 && rooms[p[0]-1][p[1]] > distance) {
                                q.push(vector<int> {p[0]-1, p[1]});
                            }
                            if (p[0] < m - 1 && rooms[p[0]+1][p[1]] > 0 && rooms[p[0]+1][p[1]] > distance) {
                                q.push(vector<int> {p[0]+1, p[1]});
                            }
                            if (p[1] > 0 && rooms[p[0]][p[1]-1] > 0 && rooms[p[0]][p[1]-1] > distance) {
                                q.push(vector<int> {p[0], p[1]-1});
                            }
                            if (p[1] < n - 1 && rooms[p[0]][p[1]+1] > 0 && rooms[p[0]][p[1]+1] > distance) {
                                q.push(vector<int> {p[0], p[1]+1});
                            }
                            q_size --;
                        }
                        distance ++;
                    }
                }
            }
        }
    }
};
