class Solution {
private:
    int partition(vector<vector<int>>& points, int l, int r) {
        int pivot_val = points[r][0] * points[r][0] + points[r][1] * points[r][1];
        int pivot = l;
        for (int i = l; i < r; i++) {
            if (points[i][0] * points[i][0] + points[i][1] * points[i][1] < pivot_val) {
                swap(points[i], points[pivot]);
                pivot ++;
            }
        }
        swap(points[r], points[pivot]);
        return pivot;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //quick select O(n)
        if (K == 0) {
            return {};
        }
        if (points.size() <= K) {
            return points;
        }
        int l = 0;
        int r = points.size() - 1;
        while (l < r) {
            int idx = partition(points, l, r);
            if (idx + 1 == K) {
                r = idx + 1;// useless, dont use l r
                break;
            }
            if (idx + 1 < K) {
                l = idx + 1;
            } else {
                r = idx - 1;
            }
        }
        return vector<vector<int>> (points.begin(), points.begin() + K);
    }
};

class Solution {
private:
    int partition(vector<vector<int>>& points, int l, int r) {
        int p_val = points[r][0] * points[r][0] + points[r][1] * points[r][1];
        int pivot = l;
        for (int i = l; i < r; i++) {
            if (points[i][0] * points[i][0] + points[i][1] * points[i][1] <= p_val) {
                swap(points[pivot], points[i]);
                pivot ++;
            }
        }
        swap(points[pivot], points[r]);
        return pivot;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (K <= 0) {
            return {};
        }
        if (K >= points.size()) {
            return points;
        }
        int l = 0;
        int r = points.size() - 1;
        while (r > l) {
            int idx = partition(points, l, r);
            if (idx + 1 == K) {
                return vector<vector<int>> (points.begin(), points.begin() + K);
            } else if (idx + 1 < K) {
                l = idx + 1;
            } else {
                r = idx - 1;
            }
        }
        return vector<vector<int>> (points.begin(), points.begin() + K);
    }
};
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
