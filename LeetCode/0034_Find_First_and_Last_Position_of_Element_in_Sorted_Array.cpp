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
