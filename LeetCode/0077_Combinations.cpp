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
