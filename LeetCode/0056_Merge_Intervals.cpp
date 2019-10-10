// 93% 97%
bool sort_by_first(const vector<int>& l, const vector<int>& r) {
    return l[0] < r[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> candidate;
        for (const vector<int>& interval : intervals) {
            if (candidate.size() == 0) {
                candidate = interval;
            } else {
                if (candidate[1] < interval[0]) {
                    res.push_back(candidate);
                    candidate = interval;
                } else {
                    candidate[1] = max(candidate[1], interval[1]);
                }
            }
        }
        if (candidate.size() > 0) {
            res.push_back(candidate);
        }
        return res;
    }
};
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
