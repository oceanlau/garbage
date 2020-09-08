class Solution {
public:
    string addBinary(string a, string b) {
        if (b.length() > a.length()) {
            swap(a, b);
        }
        int carry = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i --, j --) {
            int sum = a[i] - '0' + carry;
            carry = 0;
            if (j >= 0) {
                sum += b[j] - '0';
            }
            if (sum > 1) {
                carry = 1;
            }
            if (sum % 2) {
                a[i] = '1';
            } else {
                a[i] = '0';
            }
        }
        if (carry) {
            a = '1' + a;
        }
        return a;
    }
};

//80% 83%
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        if (a.length() < b.length()) {
            swap(a, b);
        }
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
            int sum = 0;
            if (i >= 0 && a[i] == '1') {
                sum += 1;
            }
            if (j >= 0 && b[j] == '1') {
                sum += 1;
            }
            sum += carry;
            if (sum == 3) {
                carry = 1;
                a[i] = '1';
            } else if (sum == 2) {
                carry = 1;
                a[i] = '0';
            } else if (sum == 1) {
                carry = 0;
                a[i] = '1';
            } else {
                carry = 0;
                a[i] = '0';
            }
        }
        if (carry) {
            a = '1' + a;
        }
        return a;
    }
};
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
