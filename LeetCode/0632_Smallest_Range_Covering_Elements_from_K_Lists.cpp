class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //put the first elements of the k lists into a set, range is largest - smallest. pop the smallest one and insert next one in that list
        //because we are only moving the smallest one, we can use a heap instead of set. range max can be updated on the fly.
        priority_queue<vector<int>> min_heap;
        int range_max = INT_MIN;
        for (int k = 0; k < nums.size(); k++) {
            range_max = max(range_max, nums[k][0]);
            min_heap.push({-nums[k][0], k, 0});
        }
        vector<int> range {-min_heap.top()[0], range_max};
        while (true) {
            int k = min_heap.top()[1];
            int i = min_heap.top()[2] + 1;
            min_heap.pop();
            while (i < nums[k].size() && nums[k][i] == nums[k][i-1]) {
                i ++;
            }
            if (i == nums[k].size()) {
                break;
            }
            range_max = max(range_max, nums[k][i]);
            min_heap.push({-nums[k][i], k, i});
            if (range_max + min_heap.top()[0] < range[1] - range[0] || (range_max + min_heap.top()[0] == range[1] - range[0] && -min_heap.top()[0] < range[0])) {
                range[0] = -min_heap.top()[0];
                range[1] = range_max;
            }
        }
        return range;
    }
};
