//             " -1.1e-1 "
// into state: 0012345678
class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        bool num_exists = false;
        for (const char c : s) {
            switch (state) {
                case 0:
                    if (c == ' ') {
                        continue;
                    } else if (c == '+' || c == '-') {
                        state = 1;
                    } else if (isdigit(c)) {
                        num_exists = true;
                        state = 2;
                    } else if (c == '.') {
                        state = 3;
                    } else {
                        return false;
                    }
                    break;
                case 1:
                    if (isdigit(c)) {
                        num_exists = true;
                        state = 2;
                    } else if (c == '.') {
                        state = 3;
                    } else {
                        return false;
                    }
                    break;
                case 2:
                    if (isdigit(c)) {
                        continue;
                    } else if (c == '.') {
                        state = 3;
                    } else if (c == 'e') {
                        state = 5;
                    } else if (c == ' ') {
                        state = 8;
                    } else {
                        return false;
                    }
                    break;
                case 3:
                    if (isdigit(c)) {
                        num_exists = true;
                        state = 4;
                    } else if (c == ' ') {
                        state = 8;
                    } else if (c == 'e') {
                        state = 5;
                    } else {
                        return false;
                    }
                    break;
                case 4:
                    if (isdigit(c)) {
                        continue;
                    } else if (c == 'e') {
                        state = 5;
                    } else if (c == ' ') {
                        state = 8;
                    } else {
                        return false;
                    }
                    break;
                case 5:
                    if (isdigit(c)) {
                        state = 7;
                    } else if (c == '-' || c == '+') {
                        state = 6;
                    } else {
                        return false;
                    }
                    break;
                case 6:
                    if (isdigit(c)) {
                        state = 7;
                    } else {
                        return false;
                    }
                    break;
                case 7:
                    if (isdigit(c)) {
                        continue;
                    } else if (c == ' ') {
                        state = 8;
                    } else {
                        return false;
                    }
                    break;
                case 8:
                    if (c == ' ') {
                        continue;
                    } else {
                        return false;
                    }
                    break;
            }
        }
        return num_exists && (state == 2 || state == 3 || state == 4 || state == 7 || state == 8);
    }
};
