class Solution {
public:
    string addBinary(string a, string b) {
        int plus = 0;
        int a_len = a.length();
        int b_len = b.length();
        int len = max(a_len, b_len);
        string res(len, '0');
        for(int i = 0; i < len; i ++) {
            int char_a = 0;
            if (a_len - 1 - i >= 0) {
                char_a = a[a_len - 1 - i] - '0';
            }
            int char_b = 0;
            if (b_len - 1 - i >= 0) {
                char_b = b[b_len - 1 - i] - '0';
            }
            switch(plus + char_a + char_b) {
                case 0:
                    res[len - 1 - i] = '0';
                    plus = 0;
                    break;
                case 1:
                    res[len - 1 - i] = '1';
                    plus = 0;
                    break;
                case 2:
                    res[len - 1 - i] = '0';
                    plus = 1;
                    break;
                case 3:
                    res[len - 1 - i] = '1';
                    plus = 1;
                    break;   
            }
        }
        if (plus) {
            res = '1' + res;
        }
        return res;
    }
};
