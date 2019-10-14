// 79% 38%
class Solution {
private:
    vector<string> below_20 =  vector<string> {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> below_100 =  vector<string> {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> per_1000 =  vector<string> {"Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string res;
        //section of 3 digits
        int i_1000 = 0;
        while (num > 0) {
            int n = num % 1000;
            // Corner case: Dont want "One Million Thousand"
            if (i_1000 > 0 && n > 0) {
                res = per_1000[i_1000 - 1] + " " + res;
            }
            int last_2 = n % 100;
            if (last_2 > 0) {
                if (last_2 < 20) {
                    res = below_20[last_2 - 1] + " " + res;
                } else {
                    int first = last_2%10;
                    // Corner case: No "Twenty Zero"
                    res = below_100[last_2/10 - 2] + " " + ((first > 0) ? (below_20[first - 1] + " ") : "") + res;
                }
            }
            int third_digit = n / 100;
            if (third_digit > 0) {
                res = below_20[third_digit - 1] + " Hundred " + res;
            }
            
            num /= 1000;
            i_1000 ++;
        }
        res.pop_back();
        return res;
    }
};
