class Solution {
private:
    void _backtrack(vector<int>& candidates, int target, int begin, vector<vector<int>>& solutions, vector<int>& solution) {
        if (target == 0) {
            solutions.push_back(solution);
            return;
        }
        
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i ++) {
            if (i > begin && candidates[i] == candidates[i - 1]) {
                continue;
            }
            solution.push_back(candidates[i]);
            _backtrack(candidates, target - candidates[i], i + 1, solutions, solution);
            solution.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> solutions;
        vector<int> solution;
        _backtrack(candidates, target, 0, solutions, solution);
        return solutions;
    }
};
