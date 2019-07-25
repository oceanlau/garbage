class Solution {
private:
    //assume the robot is at n,m trying to reach 0,0
    int _getDp(int n, int m, vector<vector<int>>& obstacleGrid) {
        // out-of-grid is the same as hit-obstacle
        if (n < 0 || m < 0) {
            return 1;
        } else if (obstacleGrid[n][m] != 0) {
            return obstacleGrid[n][m];
        }
        //this function works EXCEPT the destination 0,0 point
        //should be 2 even when surrounded by obstacles
        obstacleGrid[n][m] = _getDp(n - 1, m, obstacleGrid) - 1 + _getDp(n, m - 1, obstacleGrid) - 1 + 1;
        return obstacleGrid[n][m];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) {
            return 0;
        }
        int m = obstacleGrid[0].size();
        if (m == 0) {
            return 0;
        }
        // use the original obstacleGrid to record paths count:
        // 0 undefined, 1 no way, 2 one way, 3 two, ...
        if (obstacleGrid[0][0] == 0) {
            obstacleGrid[0][0] = 2;
        }
        return _getDp(n - 1, m - 1, obstacleGrid) - 1;
    }
};
