class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        queue<vector<int>> q;
        q.push({1, (nums[0] % 100) / 10, nums[0] % 10});
        int sum = 0;
        int i = 1;
        while (i < nums.size()) {
            int depth = nums[i] / 100;
            int position = (nums[i] % 100) / 10;
            int val = nums[i] % 10;
            int last_depth = q.front()[0];
            int last_position = q.front()[1];
            int last_path_sum = q.front()[2];
            // No children (right part of tree)
            if (depth != last_depth + 1) {
                sum += last_path_sum;
                q.pop();
                continue;
            }
            // No children (left part of tree)
            if (last_position * 2 - 1 != position && last_position * 2 != position) {
                sum += last_path_sum;
                q.pop();
                continue;
            }
            // Left child
            if (last_position * 2 - 1 == position) {
                q.push({depth, position, last_path_sum + val});
                i ++;
            }
            // Moved to right child
            if (i < nums.size()) {
                depth = nums[i] / 100;
                // Careful, next one may not be a right child, may be next level
                if (depth != last_depth + 1) {
                    q.pop();
                    continue;
                }
                position = (nums[i] % 100) / 10;
                val = nums[i] % 10;
            }
            // Right child
            if (last_position * 2 == position) {
                q.push({depth, position, last_path_sum + val});
                i ++;
            }
            q.pop();
        }
        while (!q.empty()) {
            sum += q.front()[2];
            q.pop();
        }
        return sum;
    }
};

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
