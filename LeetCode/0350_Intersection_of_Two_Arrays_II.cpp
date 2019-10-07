class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // naively, we could mark -1 for each match n^2
        // sort and do it in one pass, n_1 log n_1 + n_2 log n_2 + n_1 + n_2 (follow up 1)
        // sort 1 and quick select, n_1 log n_1 + n_2 log n_1 (follow up 2, let n1 be the smaller one)
        // Sort num1 and load num2 by chunks. Use quick select. Or sort num2 by chunks. Or we could use a depth 1 B tree on num2?(follow up 3)
        // quick select is actually a bit complicated in practice
        // usually use one pass or *counter*, for follow up 2, a counter would get it done in one pass without sorting
        vector<int> res;
        unordered_map<int, int> counter;
        for (const int n1 : nums1) {
            counter[n1] ++;
        }
        for (const int n2 : nums2) {
            if (counter.find(n2) != counter.end() && counter[n2] > 0) {
                res.push_back(n2);
                counter[n2] --;
            }
        }
        return res;
    }
};
