//mem 8.3m
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1/x;
            if (n == INT_MIN) {
                n = - (n + 1);
                return x * myPow(x, n);
            }
            n = -n;
        } else if (n == 0) {
            return 1;
        }
        
        return n % 2 ? x * myPow(x, n-1) : myPow(x*x, n/2);
    }
};

//mem 8.4m
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1/x;
            if (n == INT_MIN) {
                n = - (n + 1);
                return x * myPow(x, n);
            }
            n = -n;
        } else if (n == 0) {
            return 1;
        }
        
        if (n % 2) {
            return x * myPow(x, n-1);
        } else {
            double tmp = myPow(x, n/2);
            return tmp * tmp;
        }
    }
};

//mem 9.8m
class Solution {
private:
    double _x;
    unordered_map<int, double> _dp;
    double _getDp(unsigned n) {
        if (_dp.find(n) != _dp.end()) {
            return _dp[n];
        }
        _dp[n] = n % 2 ? _x*_getDp(n-1) : _getDp(n/2) * _getDp(n/2);
        return _dp[n];
    }
public:
    double myPow(double x, int n) {
        unsigned m;
        if (n < 0) {
            m = -(unsigned)n;
            x = 1/x;
        } else {
            m = n;
        }
        _x = x;
        _dp[0] = 1;
        _dp[1] = x;
        return _getDp(m);
    }
};
