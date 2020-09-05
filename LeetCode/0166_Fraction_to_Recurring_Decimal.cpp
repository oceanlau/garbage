class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // integral part
        string sign = "";
        // bug 1
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            sign = "-";
        }
        // bug 3
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        long long integral = n / d;
        // bug 2
        long long remainder = n % d;
        if (remainder == 0) {
            return sign + to_string(integral);
        }
        unordered_map<int, int> remainder_pos;
        string fraction = "";
        while (remainder > 0 && !remainder_pos.count(remainder)) {
            remainder_pos[remainder] = fraction.size();
            fraction += to_string(remainder * 10 / d);
            remainder = remainder * 10 % d;
        }
        if (remainder != 0) {
            fraction += ')';
            fraction.insert(remainder_pos[remainder], 1, '(');
        }
        return sign + to_string(integral) + '.' + fraction;
    }
};

class Solution {
private:
    string fractional(long long numerator, long long denominator) {
        string fractionalpart = "";
        unordered_map<int, int> remainder_pos;
        
        while (numerator != 0) {
            remainder_pos[numerator] = fractionalpart.length();
            fractionalpart += to_string(numerator * 10 / denominator);
            numerator = numerator * 10 % denominator;
            
            if (remainder_pos.count(numerator)) {
                fractionalpart.insert(remainder_pos[numerator], "(");
                fractionalpart += ')';
                return fractionalpart;
            }
        }
        return fractionalpart;
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        long long n = numerator;
        long long d = denominator;
        //integral part
        string integral = to_string(abs(n/d));
        if ((n < 0 && d > 0) || (n > 0 && d < 0)) {
            integral = '-' + integral;
        }
        if (n % d == 0) {
            return integral;
        }
        integral += ".";
        return integral + fractional(abs(n % d), abs(d));
    }
};
