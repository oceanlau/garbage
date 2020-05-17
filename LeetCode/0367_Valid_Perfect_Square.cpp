class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1) {
            return true;
        }
        int l = 2;
        int r = num / 2;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (num / mid == mid && num % mid == 0) {
                return true;
            } else if (num / mid < mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (num / l == l && num % l == 0) {
            return true;
        } else if (num / r == r && num % r == 0) {
            return true;
        }
        return false;
    }
};
