class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>> min_heap;
        if (nums2.size() == 0) {
            return {};
        }
        for (int i = 0; i < nums1.size() && i < k; i++) {
            min_heap.push({-(nums1[i] + nums2[0]), i, 0});
        }
        vector<vector<int>> results;
        while (results.size() < k && !min_heap.empty()) {
            vector<int> tuple = min_heap.top();
            min_heap.pop();
            results.push_back({nums1[tuple[1]], nums2[tuple[2]]});
            if (tuple[2] + 1 < nums2.size()) {
                min_heap.push({-(nums1[tuple[1]] + nums2[tuple[2]+1]), tuple[1], tuple[2] + 1});
            }
        }
        return results;
    }
};
