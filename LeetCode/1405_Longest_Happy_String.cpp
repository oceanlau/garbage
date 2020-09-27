class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        int chance = a + b + c;
        int cont_a = 0;
        int cont_b = 0;
        int cont_c = 0;
        while (chance -- > 0) {
            if (a > 0 && cont_a < 2 && ((a >= b && a >= c) || (cont_b == 2 || cont_c == 2))) {
                res += 'a';
                a --;
                cont_a ++;
                cont_b = 0;
                cont_c = 0;
            }
            if (b > 0 && cont_b < 2 && ((b >= a && b >= c) || (cont_a == 2 || cont_c == 2))) {
                res += 'b';
                b --;
                cont_b ++;
                cont_a = 0;
                cont_c = 0;
            }
            if (c > 0 && cont_c < 2 && ((c >= b && c >= a) || (cont_b == 2 || cont_a == 2))) {
                res += 'c';
                c --;
                cont_c ++;
                cont_a = 0;
                cont_b = 0;
            }
            // Dont break. Need to try again for other char
        }
        return res;
    }
};
