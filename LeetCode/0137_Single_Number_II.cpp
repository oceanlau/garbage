class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> distincts;
        long long sum = 0;
        long long distinct_sum = 0;
        for (const int num : nums) {
            if (!distincts.count(num)) {
                distinct_sum += num;
                distincts.insert(num);
            }
            sum += num;
        }
        return (3 * distinct_sum - sum) / 2;
    }
};
