class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }
        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0; i --, j --) {
            int sum = (num1[i] - '0') + carry;
            if (j >= 0) {
                sum += num2[j] - '0';
            }
            if (sum > 9) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            num1[i] = sum + '0';
        }
        if (carry) {
            num1 = '1' + num1;
        }
        return num1;
    }
};
