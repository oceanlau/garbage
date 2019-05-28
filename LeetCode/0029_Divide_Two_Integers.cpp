class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_pos = true;
        if ((dividend > 0) != (divisor > 0)) {
            is_pos = false;
        }
        long long d = dividend;
        long long r = divisor;
        d = abs(d);
        r = abs(r);
        long long quotient = getQuotient(d, r, 0);
        quotient = is_pos ? quotient : -quotient;
        if (quotient > INT_MAX || quotient < INT_MIN) {
            return INT_MAX;
        } else {
            return quotient;
        }
    }
    
    long long getQuotient (long long d, long long r, int q) {
        int exponent = 0;
        long long m = r;
        long long last_m;
        while (d > m) {
            last_m = m;
            m += m;
            exponent ++;
        }
        if (d == m) {
            return q + pow(2, exponent);
        } else if (exponent > 1) {
            return q + getQuotient(d - last_m, r, pow(2, exponent-1));
        } else {
            return q + exponent;
        } 
    }
};
