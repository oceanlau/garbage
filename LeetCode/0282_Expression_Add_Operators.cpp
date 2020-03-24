class Solution {
private:
    void _bt(vector<string>& expressions, string expression, int pos, string& num, int& target, long long cv, char po, long long pv) {
        if (pos == num.length()) {
            if (cv == target) {
                expressions.push_back(expression);
            }
            return;
        }
        
        for (int i = pos; i < num.length(); i++) {
            string cur_str = num.substr(pos, i - pos + 1);
            long long cur_num = stoll(cur_str);
            if (pos == 0) {
                _bt(expressions, cur_str, i + 1, num, target, cur_num, po, cur_num);
            } else {
                _bt(expressions, expression + '+' + cur_str, i + 1, num, target, cv + cur_num, '+', cur_num);
                _bt(expressions, expression + '-' + cur_str, i + 1, num, target, cv - cur_num, '-', -cur_num);
                _bt(expressions, expression + '*' + cur_str, i + 1, num, target, cv - pv + pv * cur_num, '*', pv * cur_num);
            }
            if (num[pos] == '0') {
                break;
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        string expression = "";
        vector<string> expressions;
        int pos = 0;
        long long cv = 0;
        char po = '+';
        long long pv = 0;
        _bt(expressions, expression, pos, num, target, cv, po, pv);
        return expressions;
    }
};
