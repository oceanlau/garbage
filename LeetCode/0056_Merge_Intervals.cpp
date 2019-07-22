//Too slow
class Solution {
private:
    static bool _comp(vector<int> interval1, vector<int> interval2) {
        return interval1[0] < interval2[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), _comp);
        vector<int> interval = intervals[0];
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i][0] <= interval[1]) {
                interval[1] = intervals[i][1] > interval[1] ? intervals[i][1] : interval[1];
            } else {
                res.push_back(interval);
                interval = intervals[i];
            }
        }
        res.push_back(interval);
        return res;
    }
};
