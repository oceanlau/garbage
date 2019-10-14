// 49% 95%
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& l, const vector<int>& r) {
            return l[0]*l[0] + l[1]*l[1] < r[0]*r[0] + r[1]*r[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
