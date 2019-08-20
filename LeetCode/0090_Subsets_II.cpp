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
