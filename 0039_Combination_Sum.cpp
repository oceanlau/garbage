// bt
class Solution {
private:
    void _backtrack(vector<int>& candidates, int target, vector<vector<int>>& solutions, vector<int>& solution, int begin) {
        if (target == 0) {
            solutions.push_back(solution);
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            solution.push_back(candidates[i]);
            _backtrack(candidates, target - candidates[i], solutions, solution, i);
            solution.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> solutions;
        vector<int> solution;
        _backtrack(candidates, target, solutions, solution, 0);
        return solutions;
    }
};

//wrong thinking
class Solution {
private:
    vector<int> _steps;
    bool _increase(vector<int>& solution) {
        //could not determine min increase
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        _steps.assign(candidates.size() - 1, 1);
        for(int i = 0; i < _steps.size(); i++) {
            _steps[i] = candidates[i + 1] / candidates[i];
        }
        vector<vector<int>> solutions;
        int longest_solution = target / candidates[0];
        while (longest_solution > 0) {
            vector<int> solution(candidates.size(), 0);
            solution[0] = longest_solution;
            do {
                int res = 0;
                for(int i = 0; i < solution.size(); i ++) {
                    res += (solution[i] * candidates[i]);
                }
                if (res == target) {
                    solutions.push_back(solution);
                } else if (res > target) {
                    break;
                }
            } while (_increase(solution));
            longest_solution --;
        }
    }
};
