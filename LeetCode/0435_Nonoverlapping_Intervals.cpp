class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // find the max remaining non-overlapping intervals
        // sort and one-pass greedy. Keeps track of smallest end number
        // overlapping and with larger end number intervals got discarded)
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int remaining = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                remaining ++;
            } else if (intervals[i][1] < end) {
                end = intervals[i][1];
            }
        }
        return intervals.size() - remaining;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int remaining = 1;
        int right_bound = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= right_bound) {
                right_bound = intervals[i][1];
                remaining ++;
            } else if (intervals[i][1] <= right_bound) {
                right_bound = intervals[i][1];
            }
        }
        return intervals.size() - remaining;
    }
};
