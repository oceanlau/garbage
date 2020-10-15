class Solution {
private:
    void _dfs(vector<vector<int>>& rooms, int room, vector<bool>& visited, int& remain) {
        if (visited[room]) {
            return;
        }
        remain --;
        visited[room] = true;
        for (const int next_room : rooms[room]) {
            _dfs(rooms, next_room, visited, remain);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int remain = rooms.size();
        vector<bool> visited(remain, false);
        _dfs(rooms, 0, visited, remain);
        return remain == 0;
    }
};
