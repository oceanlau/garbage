class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pair<int, int> last_range {INT_MAX, INT_MIN};
        for (int k = 0; k < nums.size(); k ++) {
            pq.push({nums[k][0], k, 0});
            last_range.first = min(nums[k][0], last_range.first);
            last_range.second = max(nums[k][0], last_range.second);
        }
        pair<int, int> smallest_range = last_range;
        while (true) {
            int k = pq.top()[1];
            int i = pq.top()[2] + 1;
            pq.pop();
            while (i < nums[k].size() && nums[k][i] == nums[k][i - 1]) {
                i ++;
            }
            if (i == nums[k].size()) {
                break;
            }
            pair<int, int> range {min(pq.top()[0], nums[k][i]), max(last_range.second, nums[k][i])};
            if (range.second - range.first < smallest_range.second - smallest_range.first) {
                smallest_range = range;
            }
            last_range = range;
            pq.push({nums[k][i], k, i});
        }
        return {smallest_range.first, smallest_range.second};
    }
};

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
