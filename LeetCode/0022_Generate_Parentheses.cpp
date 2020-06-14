class Solution {
private:
    void gen(vector<string>& res, string& cur, int l, int r) {
        if (l == r && l == 0) {
            res.push_back(cur);
            return;
        }
        if (l > 0) {
            cur += '(';
            gen(res, cur, l - 1, r);
            cur.pop_back();
        }
        if (r > l) {
            cur += ')';
            gen(res, cur, l, r - 1);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        gen(res, cur, n, n);
        return res;
    }
};

class Solution {
private:
    void _bt(vector<string>& results, string cur, int r_allowed, int l, int r) {
        if (l == r && r == 0) {
            results.push_back(cur);
            return;
        }
        if (l > 0) {
            _bt(results, cur + '(', r_allowed + 1, l - 1, r);
        }
        if (r > 0 && r_allowed > 0) {
            _bt(results, cur + ')', r_allowed - 1, l, r - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string cur = "";
        _bt(results, cur, 0, n, n);
        return results;
    }
};

// Right Answer
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        cache.resize(n + 1);
        cache[0] = vector<string> {""};
        cache[1] = vector<string> {"()"};
        
        return doGenerateParenthesis(n);
        
    }
    
private:
    
    vector<string> doGenerateParenthesis(int n) {
        
        if (cache[n].size() > 0) {
            return cache[n];
        }
        
        set<string> res_dedupe;
        vector<string> children = doGenerateParenthesis(n-1);
        int l = n - 1;
        int r = 1;
        
        while (l >= r) {
            vector<string> lchildren = doGenerateParenthesis(l);
            if (r == 1) {
                for (string& lchild : lchildren) {
                    res_dedupe.insert("()" + lchild);
                    res_dedupe.insert(lchild + "()");
                    res_dedupe.insert("(" + lchild + ")");
                }
            } else {
                vector<string> rchildren = doGenerateParenthesis(r);
                for (string& lchild : lchildren) {
                    for (string& rchild : rchildren) {
                        res_dedupe.insert(lchild + rchild);
                        res_dedupe.insert(rchild + lchild);
                    }
                }
            }
            l --;
            r ++;
        }
        vector<string> res(res_dedupe.begin(), res_dedupe.end());
        cache[n] = res;
        
        return res;
    }
    
    vector<vector<string>> cache;
};

class Solution {
public:
    //wrong thinking, no (())(())
    vector<string> generateParenthesis(int n) {
        if (n < 1) {
            return {};
        }
        if (n == 1) {
            return {"()"};
        }
        vector<string> res = generateParenthesis(n - 1);
        int s = res.size();
        for (int i = 0; i < s; i++) {
            string cur = res[i];
            if ("()" + cur != cur + "()") {
                res.push_back("()" + cur);
            }
            res.push_back(cur + "()");
            res[i] = "(" + cur + ")";
        }
        return res;
    }
};

// Wrong Thinking

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return vector<string> {""};
        } else if (n == 1) {
            return vector<string> {"()"};
        }

        vector<string> patterns = generateParenthesis(n-1);
        vector<string> res;
        for(string& pattern : patterns) {
            string tmp = "()" + pattern;
            res.push_back(tmp);
            res.push_back("(" + pattern + ")");
            if (pattern + "()" != tmp) {
                res.push_back(pattern + "()");
            }
        }
        return res;

    }
};
