class Solution {
public:
    string intToRoman(int num) {
        vector<vector<char*>> roman_digits {
            {"I", "V", "X"},
            {"X", "L", "C"},
            {"C", "D", "M"},
            {"M", "", ""}
        };
        string digits = to_string(num);
        short num_of_digits = digits.length() - 1;
        string res;
        for (char& c : digits) {
            res += digitToRoman(c, roman_digits[num_of_digits][0], roman_digits[num_of_digits][1], roman_digits[num_of_digits][2]);
            num_of_digits --;
        }
        return res;
        
    }
    
    string digitToRoman(char c, char* one, char* five, char* ten) {
        char roman[5] = {};
        switch (c) {
            case '1':
                snprintf(roman, 2, "%s", one);
                break;
                
            case '2':
                snprintf(roman, 3, "%s%s", one, one);
                break;
                
            case '3':
                snprintf(roman, 4, "%s%s%s", one, one, one);
                break;
                
            case '4':
                snprintf(roman, 3, "%s%s", one, five);
                break;
                
            case '5':
                snprintf(roman, 2, "%s", five);
                break;
                
            case '6':
                snprintf(roman, 3, "%s%s", five, one);
                break;
                
            case '7':
                snprintf(roman, 4, "%s%s%s", five, one, one);
                break;
                
            case '8':
                snprintf(roman, 5, "%s%s%s%s", five, one, one, one);
                break;
                
            case '9':
                snprintf(roman, 3, "%s%s", one, ten);
                break;
        }
        
        return string(roman);
    }
};
