class Solution {
private:
    void _bt(vector<int>& candidates, int start, int& target, vector<vector<int>>& combs, vector<int>& comb, int sum) {
        for (int i = start; i < candidates.size(); i++) {
            while (i > start && i < candidates.size() && candidates[i] == candidates[i-1]) {
                i++;
                continue;
            }
            if (i == candidates.size()) {
                return;
            }
            sum += candidates[i];
            comb.push_back(candidates[i]);
            if (sum > target) {
                comb.pop_back();
                return;
            } else if (sum == target) {
                combs.push_back(comb);
                comb.pop_back();
                return;
            }
            _bt(candidates, i+1, target, combs, comb, sum);
            comb.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        vector<vector<int>> combs;
        _bt(candidates, 0, target, combs, comb, 0);
        return combs;
    }
};

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
