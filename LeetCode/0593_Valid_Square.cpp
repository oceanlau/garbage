class Solution {
private:
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> edges {dist(p1, p2), dist(p1, p3), dist(p1, p4), dist(p2, p3), dist(p2, p4), dist(p3, p4)};
        int larger = -1;
        int larger_cnt = 0;
        int smaller = -1;
        int smaller_cnt = 0;
        for (const int squarelen : edges) {
            if (larger == -1) {
                larger = squarelen;
                larger_cnt ++;
            } else if (squarelen == larger) {
                larger_cnt ++;
            } else {
                if (smaller == -1) {
                    smaller = squarelen;
                    smaller_cnt ++;
                } else if (squarelen == smaller) {
                    smaller_cnt ++;
                } else {
                    return false;
                }
            }
        }
        if (larger < smaller) {
            swap(larger, smaller);
            swap(larger_cnt, smaller_cnt);
        }
        if (larger_cnt == 2 && smaller_cnt == 4 && larger == 2 * smaller) {
            return true;
        }
        return false;
    }
};
