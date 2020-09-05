class Solution {
private:
    bool _bt(string& ans, unordered_set<string>& passwords, int n, int k, int number_of_ans) {
        string password(ans.substr(ans.size() - n));
        passwords.insert(password);
        if (passwords.size() == number_of_ans) {
            return true;
        }
        int i = 0;
        password = ans.substr(ans.size() - n + 1);
        while (i < k) {
            password.push_back('0' + i);
            if (passwords.count(password)) {
                password.pop_back();
                i ++;
                continue;
            }
            ans.push_back('0' + i);
            if (_bt(ans, passwords, n, k, number_of_ans)) {
                return true;
            }
            ans.pop_back();
            password.pop_back();
            i ++;
        }
        passwords.erase(ans.substr(ans.size() - n));
        return false;
    }
public:
    string crackSafe(int n, int k) {
        int number_of_ans = pow(k, n);
        string ans(n, '0');
        unordered_set<string> passwords;
        _bt(ans, passwords, n, k, number_of_ans);
        return ans;
    }
};


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
