class Solution {
private:
    vector<vector<char>> _symbol = {
        {'I', 'V'},
        {'X', 'L'},
        {'C', 'D'},
        {'M'},
    };
public:
    string intToRoman(int num) {
        int i = 0;
        string res;
        while (num != 0) {
            int cur = num % 10;
            string cur_str;
            if (cur < 4) {
                cur_str = string(cur, _symbol[i][0]);
            } else if (cur == 4) {
                cur_str += _symbol[i][0];
                cur_str += _symbol[i][1];
            } else if (cur == 5) {
                cur_str = _symbol[i][1];
            } else if (cur == 9) {
                cur_str += _symbol[i][0];
                cur_str += _symbol[i+1][0];
            } else {
                cur_str = _symbol[i][1] + string(cur - 5, _symbol[i][0]);
            }
            res = cur_str + res;
            i ++;
            num /= 10;
        }
        return res;
    }
};

// 7% 36%
class Solution {
private:
    vector<vector<char>> _roman = {
        {'I', 'V', 'X'},
        {'X', 'L', 'C'},
        {'C', 'D', 'M'},
        {'M', 'M', 'M'}
    };
    
    string _build (int input, int lvl) {
        stringstream ss;
        if (input == 4) {
            ss << _roman[lvl][0] << _roman[lvl][1];
        } else if (input == 9) {
            ss << _roman[lvl][0] << _roman[lvl][2];
        } else {
            if (input >= 5) {
                ss << _roman[lvl][1];
                input -= 5;
            }
            while (input > 0) {
                ss << _roman[lvl][0];
                input--;
            }
        }
        return ss.str();
    }
    
public:
    string intToRoman(int num) {
        string s = "";
        int lvl = 0;
        while (num != 0) {
            s = _build(num % 10, lvl++) + s;
            num /= 10;
        }
        return s;
    }
};

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
