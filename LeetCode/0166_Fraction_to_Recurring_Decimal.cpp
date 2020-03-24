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
