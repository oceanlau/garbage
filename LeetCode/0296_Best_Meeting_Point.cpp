class Solution {
private:
    int _compute1d(vector<int>& vec) {
        int mid = vec[vec.size() / 2];
        int distance = 0;
        for (int i = 0; i < vec.size(); i++) {
            distance += abs(vec[i] - mid);
        }
        return distance;
    }
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) {
            return 0;
        }
        int w = grid[0].size();
        vector<int> vec;
        for (int i = 0; i < h; i ++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) {
                    vec.push_back(i);
                }
            }
        }
        int result = _compute1d(vec);
        vec.clear();
        for (int j = 0; j < w; j++) {
            for (int i = 0; i < h; i ++) {
                if (grid[i][j] == 1) {
                    vec.push_back(j);
                }
            }
        }
        result += _compute1d(vec);
        return result;
    }
};
