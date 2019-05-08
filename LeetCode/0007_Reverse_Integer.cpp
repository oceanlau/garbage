class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        short sign = 1;
        long long tmp = x;
        if (tmp < 0) {
            sign = -1;
            //sign * x or std::abs(x) would overflow when x==-2147483648
            tmp = sign * tmp;
        }
        while (tmp > 0) {
            r = r * 10 + tmp % 10;
            tmp = (long long) tmp / 10;
        }
        r = sign * r;
        if (r > INT_MAX || r < INT_MIN) {
            return 0;
        } else {
            return r;
        }
    }
};
