class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;
        int i = 0;
        for (; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                results.push_back(intervals[i]);
                continue;
            }
            if (intervals[i][0] > newInterval[0] && intervals[i][0] > newInterval[1]) {
                results.push_back(newInterval);
                results.push_back(intervals[i++]);
            } else {
                int left = min(intervals[i][0], newInterval[0]);
                int right = max(intervals[i][1], newInterval[1]);
                while (++i< intervals.size() && intervals[i][0] <= right) {
                    right = max(right, intervals[i][1]);
                }
                results.push_back({left, right});
            }
            break;
        }
        for (; i < intervals.size(); i++) {
            results.push_back(intervals[i]);
        }
        if (results.empty() || results.back()[1] < newInterval[0]) {
            results.push_back(newInterval);
        }
        return results;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        bool pushed = false;
        for (auto iter = intervals.begin(); iter != intervals.end(); iter ++) {
            if (!pushed) {
                if (newInterval[0] > (*iter)[1]) {
                    res.push_back(*iter);
                } else if (newInterval[1] < (*iter)[0]) {
                    res.push_back(newInterval);
                    res.push_back(*iter);
                    pushed = true;
                } else {
                    res.push_back({
                                    min((*iter)[0], newInterval[0]),
                                    max((*iter)[1], newInterval[1])
                                  });
                    pushed = true;
                }
            } else {
                if ((*iter)[0] <= res.back()[1]) {
                    res.back()[1] = max((*iter)[1], res.back()[1]);
                } else {
                    res.push_back((*iter));
                }
            }
        }
        if (!pushed) {
            res.push_back(newInterval);
        }
        return res;
    }
};
