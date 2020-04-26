class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0 || k < 0 || t < 0) {
            return false;
        }
        unordered_map<long long, long long> bucket;//val group to newest val
        int min_val = abs(*min_element(nums.begin(), nums.end()));
        long long bucket_size = (long long)t + 1; // t could be 0, could be intmax
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k + 1) {
                bucket.erase((nums[i - k - 1] + min_val) / bucket_size);
            }
            int bucket_id = ((long long)nums[i] + min_val) / bucket_size;
            if (bucket.count(bucket_id)
               || (bucket.count(bucket_id - 1) && abs(bucket[bucket_id - 1] - nums[i]) <= t)
               || (bucket.count(bucket_id + 1) && abs(bucket[bucket_id + 1] - nums[i]) <= t)) {
                return true;
            }
            bucket[bucket_id] = nums[i];
        }
        return false;
    }
};
