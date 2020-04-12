class Solution {
private:
    void _bt(int n, int start, int remain, int k, vector<int>& comb, vector<vector<int>>& results) {
        if (remain == 0) {
            if (comb.size() == k) {
                results.push_back(comb);
            }
            return;
        }
        for (int i = start + 1; i<= n; i ++) {
            comb.push_back(i);
            _bt(n, i, remain - 1, k, comb, results);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> results;
        for (int i = 1; i <= n; i++) {
            comb.push_back(i);
            _bt(n, i, k - 1, k, comb, results);
            comb.pop_back();
        }
        return results;
    }
};


class Solution {
private:
    void _getCombination(int start, int end, int k, int original_k, vector<vector<int>>& res, vector<int>& combination) {
        if (k == 0) {
            if (combination.size() == original_k) {
                res.push_back(combination);
            }
            return;
        }
        
        while (start <= end) {
            combination.push_back(start);
            _getCombination(start + 1, end, k - 1, original_k, res, combination);
            combination.pop_back();
            start ++;
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combination;
        _getCombination(1, n, k, k, res, combination);
        return res;
    }
};
