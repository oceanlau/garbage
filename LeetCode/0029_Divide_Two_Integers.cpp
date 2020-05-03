class Solution {
private:
    int half = -pow(2, 30);
public:
    int divide(int dividend, int divisor) {
        //key observation: this is the only way result would overflow! it would suddenly overflow in the middle!
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = -1;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) {
            sign = 1;
        }
        //neg has one more int than pos. save to operate in neg space
        if (dividend > 0) {
            dividend = -dividend;
        }
        if (divisor > 0) {
            divisor = -divisor;
        }
        int cur_cnt = 0;
        int total_cnt = 0;
        // careful neg space here
        while (dividend <= divisor) {
            cur_cnt = 0;
            int next_cur_cnt = -1;
            int inc_divisor = divisor;
            while (dividend <= inc_divisor) {
                dividend -= inc_divisor;
                // confirmed
                cur_cnt += next_cur_cnt;
                // doomed
                if (inc_divisor <= half) {
                    break;
                }
                inc_divisor += inc_divisor;
                next_cur_cnt += next_cur_cnt;
            }
            total_cnt += cur_cnt;
        }
        // another way to handle the only overflow case
        if (total_cnt == INT_MIN && sign == 1) {
            return INT_MAX;
        } else if (sign == 1){
            return -total_cnt;
        }
        return total_cnt;
        //actually there is no other reason to use neg cnt
    }
};

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
