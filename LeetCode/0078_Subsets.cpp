class Solution {
private:
    void _bt(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& results) {
        subset.push_back(nums[start++]);
        results.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            _bt(nums, i, subset, results);
        }
        subset.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> results;
        results.push_back(subset);
        for (int i = 0; i< nums.size(); i++) {
            _bt(nums, i, subset, results);
        }
        return results;
    } 
};

class Solution {
private:
    void _getCombination(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& combination) {
        res.push_back(combination);
        while (start < nums.size()) {
            combination.push_back(nums[start]);
            _getCombination(nums, start + 1, res, combination);
            combination.pop_back();
            start ++;
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> combination;
        _getCombination(nums, 0, res, combination);
        return res;
    }
};
