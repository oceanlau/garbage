class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 1;
        for (int i = digits.size() - 1; i >= 0 && plus > 0; i--) {
            if (digits[i] + plus > 9) {
                plus = 1;
                digits[i] = digits[i] + plus - 10;
                if (i == 0) {
                    digits.insert(digits.begin(), 1, 1);
                    break;
                }
            } else {
                digits[i] = digits[i] + plus;
                plus = 0;
            }
        }
        return digits;
    }
};
