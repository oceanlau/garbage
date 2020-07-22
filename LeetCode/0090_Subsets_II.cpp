class Solution {
private:
    void _bt(int start, vector<int>& nums, vector<int>& subset, vector<vector<int>>& subsets) {
        if (start >= nums.size()) {
            return;
        }
        for (int i = start; i < nums.size();) {
            subset.push_back(nums[i]);
            subsets.push_back(subset);
            _bt(++ i, nums, subset, subsets);
            subset.pop_back();
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i ++;
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> subsets {subset};
        _bt(0, nums, subset, subsets);
        return subsets;
    }
};

// 33% -> 84% with a simple nums_size cache
class Solution {
private:
    void _getDp (vector<vector<int>>& solutions, vector<int>& solution, vector<int>& nums, int start, int nums_size) {
        solutions.push_back(solution);
        
        while (start != nums_size) {
            solution.push_back(nums[start]);
            _getDp(solutions, solution, nums, ++start, nums_size);
            while(start != nums_size && nums[start - 1] == nums[start]){
                start ++;
            }
            solution.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solutions;
        vector<int> solution;
        _getDp(solutions, solution, nums, 0, nums.size());
        return solutions;
    }
};
