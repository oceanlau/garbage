class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> loc;
        for (int i = 0; i < nums.size(); i++) {
            if (loc.count(target - nums[i])) {
                return {loc[target-nums[i]], i};
            }
            loc[nums[i]] = i;
        }
        return {};
    }
};

/*
 * Solution 1: HashMap
 * Solution 2: Sort
 */

// Solution 1: HashMap
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        int i = 0;
        for (const auto& num : nums) {
            nums_map.insert({num, i});
            i++;
        }

        i = 0;
        int tmp;
        for (const auto& num : nums) {
            tmp = target - num;
            if (nums_map.find(tmp) != nums_map.end() && i != nums_map[tmp]) {
                return {i, nums_map[tmp]};
            }
            i++;
        }
        return {};
    }
};
*/

// Solution 2: Sort
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> nums_sorted = nums;

        sort(nums_sorted.begin(), nums_sorted.end());
        int first = 0;
        int last = nums_sorted.size() - 1;
        int sum;
        int i = 0;
        while (first < last) {
            sum = nums_sorted[first] + nums_sorted[last];
            if (sum > target) {
                last--;
            } else if (sum < target) {
                first++;
            } else if (sum == target) {
                for (const auto& num : nums) {
                    if(num == nums_sorted[first] || num == nums_sorted[last]) {
                        result.push_back(i);
                    }
                    i++;
                }
                break;
            }
        }

        return result;
    }
};
