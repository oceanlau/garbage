class Solution {
public:
    string convertToTitle(int n) {
        // Decimal to 26
        string result;
        while (n > 0) {
            result = (char)((n - 1) % 26 + 'A') + result;
            n = (n - 1) / 26;
        }
        return result;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n != 0) {
            n -= 1;
            s = char(n % 26 + 'A') + s;
            n /= 26;
        }
        return s;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n != 0) {
            if (n % 26 == 0) {
                s = 'Z' + s;
                n = n/26 - 1;
            } else {
                s = char(n % 26 + 'A' - 1) + s;
                n /= 26;
            }
        }
        return s;
    }
};
