class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        bool init_flag = true;
        int closest_distance;
        int res;
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); i < nums.end() - 2; i++) {
            auto j = i + 1;
            auto k = nums.end() - 1;
            int sum = *i + *j + *k;
            int sum_tmp = sum;
            int closest_distance_tmp = abs(sum - target);
            if (init_flag) {
                res = sum;
                closest_distance = closest_distance_tmp;
                init_flag = false;
            }
            while (k > j) {
                if (sum > target) {
                    if (sum - target < closest_distance_tmp) {
                        closest_distance_tmp = sum - target;
                        sum_tmp = sum;
                    }
                    k --;
                } else if (sum < target) {
                    if (target - sum < closest_distance_tmp) {
                        closest_distance_tmp = target - sum;
                        sum_tmp = sum;
                    }
                    j ++;
                } else {
                    return sum;
                }
                sum = *i + *j + *k;
            }
            if (closest_distance_tmp < closest_distance) {
                res = sum_tmp;
                closest_distance = closest_distance_tmp;
            }
        }
        return res;
    }
};
