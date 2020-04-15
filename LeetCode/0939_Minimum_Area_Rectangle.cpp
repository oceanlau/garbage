class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> x_to_ys;
        for (const vector<int>& point : points) {
            x_to_ys[point[0]].insert(point[1]);
        }
        int min_area = 0;
        for (auto l = x_to_ys.begin(); l != x_to_ys.end(); l ++) {
            if (l->second.size() < 2) {
                continue;
            }
            for (auto r = next(l); r != x_to_ys.end(); r++) {
                if (r->second.size() < 2) {
                    continue;
                }
                for (auto y0 = l->second.begin(); y0 != l->second.end(); y0++) {
                    for (auto y1 = next(y0); y1 != l->second.end(); y1++) {
                        if (r->second.count(*y0) && r->second.count(*y1)) {
                            if (min_area == 0) {
                                min_area = (*y1 - *y0) * abs(r->first - l->first);
                            } else {
                                min_area = min(min_area, (*y1 - *y0) * abs(r->first - l->first));
                            }
                        }
                    }
                }
            }
        }
        return min_area;
    }
};
