class Solution {
private:
    void _bt(vector<int>& nums, int start, vector<int>& subseq, vector<vector<int>>& subseqs) {
        /*
        if (start == nums.size()) {
            return;
        }*///no skip answers!
        if (subseq.size() > 1) {
            subseqs.push_back(subseq);
        }
        unordered_set<int> this_lvl;
        for (int i = start; i < nums.size(); i++) {
            if ((subseq.empty() || nums[i] >= subseq.back()) && !this_lvl.count(nums[i])) {
                this_lvl.insert(nums[i]);
                subseq.push_back(nums[i]);
                _bt(nums, i + 1, subseq, subseqs);
                subseq.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> subseqs;
        vector<int> subseq;
        //no for loop out here, then for loop inside with different starting i
        _bt(nums, 0, subseq, subseqs);
        return subseqs;
    }
};
