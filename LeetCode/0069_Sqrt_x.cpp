class Solution {
private:
    int _findSqrt(int left, int right, int target) {
        int mid = (left + right) / 2;
        unsigned long long mid_sqr = mid;
        mid_sqr *= mid_sqr;
        unsigned long long mid_1_sqr = mid + 1;
        mid_1_sqr *= mid_1_sqr;
        if (mid_1_sqr <= target) {
            if (mid_1_sqr == target) {
                return mid + 1;
            }
            return _findSqrt(mid + 1, right, target);
        } else if (mid_sqr > target) {
            return _findSqrt(left, mid, target);
        }
        return mid;
    }
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        return _findSqrt(0, x/2, x);
    }
};
