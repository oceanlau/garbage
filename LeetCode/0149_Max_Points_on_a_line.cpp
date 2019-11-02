//31% 35%
class Solution {
private:
    int _gcd (int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int max_cnt = 0;
        for (int i = 0; i < points.size(); i ++) {
            int local_max = 0;
            int dupe = 1;
            unordered_map<string, int> slope_counter;
            for (int j = i + 1; j < points.size(); j ++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                if (dy == 0 && dx == 0) {
                    dupe ++;
                    continue;
                }
                int gcd = _gcd(dy, dx);
                dy /= gcd;
                dx /= gcd;
                //why this work? gcd always the same sign as numerator!
                string slope = to_string(dy) + "_" + to_string(dx);
                local_max = max(local_max, ++slope_counter[slope]);
            }
            max_cnt = max(max_cnt, local_max + dupe);
        }
        return max_cnt;
    }
};

//51% 35%
class Solution {
private:
    int _gcd (int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int max_cnt = 0;
        for (int i = 0; i < points.size(); i ++) {
            int local_max = 0;
            int dupe = 1;
            unordered_map<string, int> slope_counter;
            for (int j = i + 1; j < points.size(); j ++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                if (dy == 0 && dx == 0) {
                    dupe ++;
                    continue;
                }
                int gcd = _gcd(dy, dx);
                dy /= gcd;
                dx /= gcd;
                string slope;
                if(dy > 0 && dx < 0) {
                    slope = to_string(dy) + "-" + to_string(-dx);
                } else if (dy < 0 && dx > 0) {
                    slope = to_string(-dy) + "-" + to_string(dx);
                } else if (dy < 0 && dx < 0) {
                    slope = to_string(-dy) + "+" + to_string(-dx);
                } else {
                    slope = to_string(dy) + "+" + to_string(dx);
                }
                local_max = max(local_max, ++slope_counter[slope]);
            }
            max_cnt = max(max_cnt, local_max + dupe);
        }
        return max_cnt;
    }
};
