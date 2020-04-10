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
