class Solution {
public:
    bool checkValidString(string s) {
        int counter = 0;
        int slack = 0;
        for (const char c : s) {
            switch (c) {
                case '(':
                    counter ++;
                    break;
                case ')':
                    counter --;
                    break;
                case '*':
                    slack ++;
                    break;
            }
            if (counter < 0 && -counter > slack) {
                return false;
            }
        }
        /* // slack can be empty string
        if (slack < abs(counter) || (slack - abs(counter)) % 2 == 1) {
            return false;
        }
        */
        if (slack < abs(counter)) {
            return false;
        }
        reverse(s.begin(), s.end());
        counter = 0;
        slack = 0;
        for (const char c : s) {
            switch (c) {
                case '(':
                    counter --;
                    break;
                case ')':
                    counter ++;
                    break;
                case '*':
                    slack ++;
                    break;
            }
            if (counter < 0 && -counter > slack) {
                return false;
            }
        }
        return true;
    }
};
