// 100% 66% complicated
class Solution {
public:
    int lower(int max_depth, int depth, int pos) {
        if (max_depth - depth == 1) {
            return 2*pos - 1;
        } else {
            return 2*lower(max_depth, depth + 1, pos)-1;
        }
    }
    
    int upper(int max_depth, int depth, int pos) {
        if (max_depth - depth == 1) {
            return 2*pos;
        } else {
            return 2*upper(max_depth, depth + 1, pos);
        }
    }
    int pathSum(vector<int>& nums) {
        int depth = nums.back() / 100;
        int max_depth = depth;
        int i = nums.size() - 1;
        vector<int> sums(pow(2, max_depth-1), -1);
        while (i >= 0 && nums[i] / 100 == max_depth) {
            sums[(nums[i] / 10) % 10 - 1] = nums[i] % 10;
            i --;
        }
        depth --;
        while (depth >= 1) {
            while (i >= 0 && nums[i] / 100 == depth) {
                int l = lower(max_depth, depth, (nums[i] / 10) % 10);
                int u = upper(max_depth, depth, (nums[i] / 10) % 10);
                bool at_least_one = false;
                while (l <= u) {
                    if (sums[l - 1] != -1) {
                        at_least_one = true;
                        sums[l - 1] += nums[i] % 10;
                    }
                    l++;
                }
                if (!at_least_one) {
                    //pick one
                    sums[u - 1] = nums[i] % 10;
                }
                i--;
            }
            depth --;
        }
        int sum = 0;
        for (const int res : sums) {
            if (res != -1) {
                sum += res;
            }
        }
        return sum;
    }
};
