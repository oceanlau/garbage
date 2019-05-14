class Solution {
public:
    int romanToInt(string s) {
        int val;
        // with without zero makes big difference
        int res = 0;
        char last_c = '\0';
        for (char& c : s) {
            switch (c) {
                case 'M':
                    val = 1000;
                    if (last_c == 'C') {
                        val = 800;
                    }
                    break;
                case 'D':
                    val = 500;
                    if (last_c == 'C') {
                        val = 300;
                    }
                    break;
                case 'C':
                    val = 100;
                    if (last_c == 'X') {
                        val = 80;
                    }
                    break;
                case 'L':
                    val = 50;
                    if (last_c == 'X') {
                        val = 30;
                    }
                    break;
                case 'X':
                    val = 10;
                    if (last_c == 'I') {
                        val = 8;
                    }
                    break;
                case 'V':
                    val = 5;
                    if (last_c == 'I') {
                        val = 3;
                    }
                    break;
                case 'I':
                    val = 1;
                    break;
            }
            last_c = c;
            res += val;
        }
        return res;
    }
};
