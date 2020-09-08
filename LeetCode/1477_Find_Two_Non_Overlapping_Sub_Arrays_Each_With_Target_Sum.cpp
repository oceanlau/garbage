class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // Tricky part: each location records valid min length so far
        vector<int> min_lens(arr.size(), arr.size() + 1);
        unordered_map<int, int> prefix_sums; // with location
        prefix_sums[0] = -1;
        int sum = 0;
        int min_sum_len = arr.size() + 1;
        for (int i = 0; i < arr.size(); i ++) {
            sum += arr[i];
            prefix_sums[sum] = i;
            int len = arr.size() + 1;
            if (prefix_sums.count(sum - target)) {
                len = i - prefix_sums[sum - target];
                if (prefix_sums[sum - target] >= 0) {
                    min_sum_len = min(min_sum_len, len + min_lens[prefix_sums[sum - target]]);
                }
            }
            if (i > 0) {
                min_lens[i] = min(min_lens[i - 1], len);
            } else {
                min_lens[i] = len;
            }
        }
        return min_sum_len == arr.size() + 1 ? -1 : min_sum_len;
    }
};
