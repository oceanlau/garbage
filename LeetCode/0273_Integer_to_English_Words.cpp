class Solution {
private:
    vector<string> below_20 = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",       "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> below_100 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> per_1000 = {"Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        //corner case!
        if (num == 0) {
            return "Zero";
        }
        string res;
        int per_thousand_cnt = -1;
        //每千位处理一次 
        while (num > 0) {
            int n = num % 1000;
            // corner case!
            if (n != 0 && per_thousand_cnt > -1) {
                res = per_1000[per_thousand_cnt] + " " + res;
            }
            //十位
            int last_2 = n % 100;
            if (last_2 != 0) {
                if (last_2 < 20) {
                    res = below_20[last_2 - 1] + " " + res;
                } else {
                    int first = last_2 % 10;
                    int second = last_2 / 10;
                    //注意个位
                    if (first != 0) {
                        res = below_100[second - 2] + " " + below_20[first - 1] + " " + res;
                    } else {
                        res = below_100[second - 2] + " " + res;
                    }
                }
            }
            //百位
            int third = n / 100;
            if (third != 0) {
                res = below_20[third - 1] + " Hundred " + res;
            }
            num /= 1000;
            per_thousand_cnt ++;
        }
        //注意最后多一个空格
        //or substr
        res.pop_back();
        return res;
    }
};

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
