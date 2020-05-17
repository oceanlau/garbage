class Solution {
private:
    bool _isValid(string s, int& lp, int& rp) {
        lp = 0;
        rp = 0;
        for (const char c : s) {
            if (c == '(') {
                lp ++;
            } else if (c == ')') {
                if (lp > 0) {
                    lp --;
                } else {
                    rp ++;
                }
            }
        }
        return lp == 0 && rp == 0;
    }
    void _dfs(string s, int start, int lp, int rp, vector<string>& res) {
        //careful!
        if (lp == 0 && rp == 0) {
            if (_isValid(s, lp, rp)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (s[i] == '(' && lp > 0 && (i == 0 || s[i] != s[i-1])) {
                _dfs(s.substr(0, i) + s.substr(i + 1), i, lp - 1, rp, res);
            } else if (s[i] == ')' && rp > 0 && (i == 0 || s[i] != s[i-1])) {
                _dfs(s.substr(0, i) + s.substr(i + 1), i, lp, rp - 1, res);
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int lp = 0;
        int rp = 0;
        if (_isValid(s, lp, rp)) {
            return {s};
        }
        vector<string> res;
        _dfs(s, 0, lp, rp, res);
        return res;
    }
};

//DFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (is_valid(s)) {
            return {s};
        }
        vector<string> res;
        int lp_remove_cnt = 0;
        int rp_remove_cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                lp_remove_cnt ++;
            } else if (s[i] == ')') {
                if (lp_remove_cnt > 0) {
                    lp_remove_cnt --;
                } else {
                    rp_remove_cnt ++;
                }
            }
        }
        dfs(s, 0, lp_remove_cnt, rp_remove_cnt, res);
        return res;
    }
    
    bool is_valid(string s) {
        int counter = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            } else if (s[i] == '(') {
                counter ++;
            } else {
                counter--;
            }
            if (counter < 0) {
                return false;
            }
        }
        return counter == 0;
    }
    
    void dfs(string cur, int start, int lp_remove_cnt, int rp_remove_cnt, vector<string>& res) {
        if (lp_remove_cnt == 0 && rp_remove_cnt == 0) {
            if (is_valid(cur)) {
                res.push_back(cur);
            }
            return;
        }
        for (int i = start; i < cur.length(); i++) {
            if (cur[i] != '(' && cur[i] != ')') {
                continue;
            }
            if (cur[i] == '(' && lp_remove_cnt > 0
                && (i == start || cur[i-1] != cur[i]) ) {
                dfs(cur.substr(0, i) + cur.substr(i + 1), i, lp_remove_cnt - 1, rp_remove_cnt, res);
            }
            if (cur[i] == ')' && rp_remove_cnt > 0
                && (i == start || cur[i-1] != cur[i]) ) {
                dfs(cur.substr(0, i) + cur.substr(i + 1), i, lp_remove_cnt, rp_remove_cnt - 1, res);
            }
        }
    }
};
//BFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (is_valid(s)) {
            return {s};
        }
        queue<pair<string, int>> candidates;
        vector<string> res;
        candidates.push(make_pair(s, 0));
        // queue not empty and res empty
        // record queue size (for this level), while size not zero
        // is_valid push to res
        // else remove 'next' 'non-duplicate' char, push to queue
        
        while (!candidates.empty() && res.empty()) {
            int candidates_size = candidates.size();
            while (candidates_size > 0) {
                pair<string, int> candidate = candidates.front();
                candidates.pop();
                if (is_valid(candidate.first)) {
                    res.push_back(candidate.first);
                } else if (res.empty()) {
                    // dont go back
                    for (int i = candidate.second; i < candidate.first.size(); i++) {
                        // avoid non parentheses and duplicate char
                        if ( (candidate.first[i] == '(' || candidate.first[i] == ')')
                            // delete the first non dupe, not the last. otherwise would skip many possible ans like )) -> ""
                            //&& (i == candidate.first.size() - 1 || candidate.first[i] != candidate.first[i+1]) ) {
                            && (i == candidate.second || candidate.first[i-1] != candidate.first[i]) ) {
                            candidates.push(make_pair(candidate.first.substr(0, i) + candidate.first.substr(i + 1), i));
                        }
                    }
                }
                candidates_size --;
            }
        }
        return res;
    }
    bool is_valid(string s) {
        int counter = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            } else if (s[i] == '(') {
                counter ++;
            } else {
                counter--;
            }
            if (counter < 0) {
                return false;
            }
        }
        return counter == 0;
    }
};
