class Solution {
private:
    int numOfMinutes(int n, int id, vector<vector<int>>& subordinates, vector<int>& informTime) {
        if (subordinates[id].empty()) {
            return 0;
        }
        int maxTime = 0;
        for (int i = 0; i < subordinates[id].size(); i++) {
            maxTime = max(maxTime, numOfMinutes(n, subordinates[id][i], subordinates, informTime));
        }
        return informTime[id] + maxTime;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n, vector<int> {});
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] != -1) {
                subordinates[manager[i]].push_back(i);
            }
        }
        return numOfMinutes(n, headID, subordinates, informTime);
    }
};
