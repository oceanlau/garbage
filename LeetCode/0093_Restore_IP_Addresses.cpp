class Solution {
private:
    void _bt(string s, int& min_len, int& max_len, int remaining, vector<string>& ips, string ip) {
        if (remaining == 1) {
            if (isValid(s)) {
                ip += '.' + s;
                ips.push_back(ip);
            }
            return;
        }
        //careful
        for (int i = min_len; i <= max_len && i < s.length(); i++) {
            string seg = s.substr(0, i);
            if (isValid(seg)) {
                string tmp = ip;
                if (ip == "") {
                    ip = seg;
                } else {
                    ip += '.' + seg;
                }
                _bt(s.substr(i), min_len, max_len, remaining - 1, ips, ip);
                //careful
                ip = tmp;
            }
        }
    }
    bool isValid(string s) {
        if (s.length() > 3 || s.length() == 0) {
            return false;
        }
        if (s.length() > 1 && s[0] == '0'){
            return false;
        }
        int seg = stoi(s);
        if (seg > 255) {
            return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int min_len = 1;
        int max_len = 3;
        if (s.length() < 4) {
            return {};
        } else if (s.length() > 10) {
            if (s.length() == 12) {
                min_len = 3;
            } else {
                min_len = 2;
            }
        } else if (s.length() < 6) {
            if (s.length() == 4) {
                max_len = 1;
            } else {
                max_len = 2;
            }
        }
        vector<string> ips;
        _bt(s, min_len, max_len, 4, ips, "");
        return ips;
    }
};

//not char buffer then, 100% 91.67%
class Solution {
    private:
        void _get_segment(vector < string > & results, vector<string>& result, string input, int input_size, int nth_segment, int nth_input) {
            if (nth_segment == 4) {
                if (nth_input == input_size) {
                     stringstream s;
                     s << result[0];
                     int i = 1;
                     while (i < 4) {
                         s << '.' << result[i];
                         i++;
                     }
                     results.push_back(s.str());
                }
                return;
            } else if (nth_input >= input_size) {
                return;
            }
            int steps = 1; //at least cut 1 character
            int steps_max = 3;
            if (input[nth_input] == '0') {
                steps_max = 1;
            }
            for (; steps <= steps_max; steps++) {
                string substring = input.substr(nth_input, steps);
                if (stoi(substring) > 255) {
                    return;
                }
                result[nth_segment] = substring;
                _get_segment(results, result, input, input_size, nth_segment + 1, nth_input + steps);
            }

        }
    public:
        vector < string > restoreIpAddresses(string s) {
            vector < string > results {};
            vector < string > result (4, "");
            _get_segment(results, result, s, s.length(), 0, 0);
            return results;
        }
};

//clean code, but getting worse 67.85% 16.67%
class Solution {
    private:
        char _buffer[20];
        void _get_segment(vector < string > & results, string result, string input, int input_size, int nth_segment, int nth_input) {
            if (nth_segment == 4) {
                if (nth_input == input_size) {
                    results.push_back(result);
                }
                return;
            } else if (nth_input >= input_size) {
                return;
            }
            int steps = 1; //at least cut 1 character
            int steps_max = 3;
            if (input[nth_input] == '0') {
                steps_max = 1;
            }
            for (; steps <= steps_max; steps++) {
                string substring = input.substr(nth_input, steps);
                if (stoi(substring) > 255) {
                    return;
                }
                snprintf(_buffer, sizeof(_buffer), 
                         (nth_segment == 0) ? "%s%s":"%s.%s",
                         result.c_str(), substring.c_str());
                _get_segment(results, _buffer, input, input_size, nth_segment + 1, nth_input + steps);
            }

        }
    public:
        vector < string > restoreIpAddresses(string s) {
            vector < string > results {};
            string result = "";
            _get_segment(results, result, s, s.length(), 0, 0);
            return results;
        }
};


//no presumed optimization 100% 58.33%
class Solution {
    private:
        void _get_segment(vector < string > & results, string result, string input, int input_size, int nth_segment, int nth_input) {
            if (nth_segment == 4) {
                if (nth_input == input_size) {
                    results.push_back(result);
                }
                return;
            } else if (nth_input >= input_size) {
                return;
            }
            int steps = 1; //at least cut 1 character
            int steps_max = 3;
            if (input[nth_input] == '0') {
                steps_max = 1;
            }
            for (; steps <= steps_max; steps++) {
                string substring = input.substr(nth_input, steps);
                if (stoi(substring) > 255) {
                    return;
                }
                _get_segment(results, result + (nth_segment == 0 ? "" : ".") + substring, input, input_size, nth_segment + 1, nth_input + steps);
            }

        }
    public:
        vector < string > restoreIpAddresses(string s) {
            vector < string > results {};
            string result = "";
            _get_segment(results, result, s, s.length(), 0, 0);
            return results;
        }
};

//presumed optimization 67.91% 91.67%. Why slower?
class Solution {
private:
    //result join by '.', then push into results
    void _get_segment(vector<string>& results, vector<string>& result, string input, int input_size, int nth_segment, int nth_input) {
        if (nth_segment == 4) {
            stringstream s;
            s << result[0];
            int i = 1;
            while (i < 4) {
                s << '.' << result[i];
                i++;
            }
            results.push_back(s.str());
            return;
        }
        if (input_size - nth_input - 3*(4-nth_segment-1) > 3) {
            return;
        }
        int steps = 1;
        int steps_max = input_size - nth_input - (4-nth_segment-1);
        if (steps_max < 1) {
            return;
        } else if (steps_max > 3) {
            if (nth_segment == 3) {
                return;
            }
            steps_max = 3;
        }
        if (nth_segment == 3) {
            if (input[nth_input] == '0' && steps_max > 1) {
                return;
            }
            steps = steps_max;
        }
        if (input[nth_input] == '0') {
            steps_max = 1;
        }
        for (; steps <= steps_max; steps++) {
            string substring = input.substr(nth_input, steps);
            if (stoi(substring) > 255) {
                return;
            }
            result[nth_segment] = substring;
            _get_segment(results, result, input, input_size, nth_segment + 1, nth_input + steps);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results {};
        vector<string> result (4, "");
        _get_segment(results, result, s, s.length(), 0, 0);
        return results;
    }
};
