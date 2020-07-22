class Solution {
public:
    string multiply(string num1, string num2) {
        string result (num1.length() + num2.length(), '0');
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int sum = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                result[i + j + 1] = sum % 10 + '0';
                result[i + j] += sum / 10;
            }
        }
        for (int i = 0; i < result.length(); i++) {
            if (result[i] != '0') {
                return result.substr(i);
            }
        }
        return "0";
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }
        string res = "";
        int sum = 0;
        int num1_left = num1.length() - 1;
        int num1_right = num1_left;
        int num2_left = num2.length() - 1;
        int num2_right = num2_left;
        bool expanding_left_participant = num1_left != 0;
        while (num2_right >= 0) {
            for (int i = num1_left, j = num2_right; i <= num1_right && j >= max(0, num2_left); i++, j--) {
                sum += (num1[i] - '0') * (num2[j] - '0');
            }
            res = to_string(sum % 10) + res;
            sum /= 10;
            if (expanding_left_participant) {
                num1_left --;
                num2_left --;
                if (num1_left == 0) {
                    expanding_left_participant = false;
                }
            } else {
                num1_right --;
                num2_right --;
            }
        }
        if (sum > 0) {
            res = to_string(sum) + res;
        }
        return res;
    }
};

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
