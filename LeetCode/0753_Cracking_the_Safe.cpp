//backtrack
//starts with n '0'

class Solution {
private:
    bool _bt(int num_of_ans, string& ans, unordered_set<string>& pwds, int n, int k) {
        if (pwds.size() == num_of_ans) {
            return true;
        }
        int idx = ans.length() - n;
        string pwd = ans.substr(idx+1);
        int i = 0;
        while(i != k) {
            pwd += '0' + i;
            if (pwds.count(pwd)) {
                pwd.pop_back();
                i++;
                continue;
            }
            pwds.insert(pwd);
            ans += '0' + i;
            if (_bt(num_of_ans, ans, pwds, n, k)) {
                return true;
            }
            pwds.erase(pwd);
            pwd.pop_back();
            ans.pop_back();
            i++;
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        int num_of_ans = pow(k, n);
        string ans(n, '0');
        unordered_set<string> pwds {ans};
        int pwd_idx = 0;
        _bt(num_of_ans, ans, pwds, n, k);
        return ans;
    }
};
