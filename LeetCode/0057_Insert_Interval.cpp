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
