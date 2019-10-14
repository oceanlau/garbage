// 100% 46.67%
class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) {
            return false;
        }
        // Realize that order of factors does not really matter
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
};

//100% 40%
class Solution {
public:
    bool isUgly(int num) {
        // Careful about dead loop!
        if (num == 0) {
            return false;
        }
        vector<int> factors{2,3,5};
        // Careful about dead loop!!!
        while (num != 1) {
            // Var name matters!
            bool is_potentially_ugly = false;
            for (const int factor : factors) {
                if (num % factor == 0) {
                    is_potentially_ugly = true;
                    num /= factor;
                    break;
                }
            }
            if (!is_potentially_ugly) {
                return false;
            }
        }
        return true;
    }
};
