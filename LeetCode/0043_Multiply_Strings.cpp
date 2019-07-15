class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "0";
        if (num1 == "0" || num2 == "0") {
            return res;
        }
        int size1 = num1.length();
        int size2 = num2.length();
        for (int i = size2 - 1; i >= 0; i--) {
            int add_more = 0;
            int tmp = 0;
            for (int j = size1 - 1; j >= 0; j--) {
                int current_res = res.length() - 1 - (size1 - 1 - j) - (size2 - 1 - i);
                tmp = (num1[j] - '0') * (num2[i] - '0');
                if (current_res >= 0) {
                    tmp += res[current_res] - '0';
                }
                if (add_more) {
                    tmp += add_more;
                }
                if (tmp >= 10) {
                    add_more = tmp / 10;
                } else {
                    add_more = 0;
                }
                if (current_res >= 0) {
                    res[current_res] = '0' + tmp % 10;
                } else {
                    res = (char)('0' + tmp % 10) + res;
                } 
            }
            if (add_more) {
                res = (char)('0' + add_more) + res;
            }
        }
        return res;
    }
};
