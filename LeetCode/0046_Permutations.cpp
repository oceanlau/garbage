//bt, swap
class Solution {
private:
    vector<int> _nums;
    void _bt(vector<vector<int>>& permutations, vector<int>& permutation, int begin, int end) {
        if (begin == end) {
            permutation.push_back(_nums[end]);
            permutations.push_back(permutation);
            permutation.pop_back();
            return;
        }
        for (int i = begin; i <= end; i++) {
            swap(_nums[begin], _nums[i]);
            permutation.push_back(_nums[begin]);
            _bt(permutations, permutation, begin + 1, end);
            permutation.pop_back();
            swap(_nums[begin], _nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        _nums = nums;
        vector<vector<int>> permutations;
        vector<int> permutation;
        int end = nums.size() - 1;
        if (end < 0) {
            permutations.push_back(permutation);
            return permutations;
        }
        _bt(permutations, permutation, 0, end);
        return permutations;
    }
};
