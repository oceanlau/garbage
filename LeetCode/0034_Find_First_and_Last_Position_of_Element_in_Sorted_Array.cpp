class Solution {
public:
    // greater or equal than target (return last idx of target if equal or first idx if greater)
    int findGE (vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                l = mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] >= target) {
            if (nums[r] == target) {
                return r;
            }
            return l;
        } else if (nums[r] < target) {
            return -1;
        }
        return r;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int r = findGE(nums, target);
        if (r == -1 || nums[r] != target) {
            return {-1, -1};
        }
        int l = findGE(nums, target - 1);
        if (nums[l] == target - 1) {
            l += 1;
        }
        return {l, r};
    }
};

class Solution {
private:
    int firstGE(vector<int>& nums, int target, int i, int j) {
        while (j - i > 1) {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= target && nums[mid-1] < target) {
                return mid;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        if (nums[i] >= target) {
            return i;
        } else if (nums[j] >= target) {
            return j;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int i = firstGE(nums, target, 0, nums.size() - 1);
        if (i == -1 || nums[i] != target) {
            return {-1, -1};
        }
        int j = firstGE(nums, target + 1, i, nums.size() - 1);
        if (j == -1) {
            return {i, (int)nums.size() - 1};
        }
        return {i, j - 1};
    }
};

class Solution {
private:
    int _find(const vector<int>& nums, int left, int right, int target) {
        if (left == right || left + 1 == right) {
            if (nums[left] == target) {
                return left;
            } else if (nums[right] == target) {
                return right;
            }
            return -1;
        }
        int center = (left + right) / 2;
        if (nums[center] == target) {
            return center;
        } else if (target < nums[center]) {
            return _find(nums, left, center, target);
        } else {
            return _find(nums, center, right, target);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int> {-1, -1};
        }
        int l = _find(nums, 0, nums.size() - 1, target);
        if (l == -1) {
            return vector<int> {-1, -1};
        }
        int r = l;
        while (l >= 0) {
            l --;
            if (l < 0 || nums[l] != target) {
                l ++;
                break;
            }
        }
        while (r < nums.size()) {
            r ++;
            if (r >= nums.size() || nums[r] != target) {
                r --;
                break;
            }
        }
        return vector<int> {l, r};
    }
};
