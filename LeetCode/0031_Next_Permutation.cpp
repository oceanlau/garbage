class Solution {
private:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l ++], nums[r --]);
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size();
        if (i < 2) {
            return;
        }
        i -= 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i --;
        }
        if (i == -1) {
            reverse(nums, 0, nums.size() - 1);
        } else {
            int j = i + 1;
            while (j + 1 < nums.size() && nums[j + 1] > nums[i]) {
                j ++;
            }
            swap(nums[i], nums[j]);
            reverse(nums, i + 1, nums.size() - 1);
        }
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = nums.size() - 1; j > i; j --) {
                    if (nums[i] < nums[j]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int target = -1;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                target = i - 1;
                break;
            }
        }
        if (target == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > target; i--) {
            if (nums[i]  > nums[target]) {
                swap(nums[i], nums[target]);
                break;
            }
        }
        reverse(nums.begin() + target + 1, nums.end());
        return;
        
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n <= 0) {
            return;
        }
        int max_right = nums[n];
        n --;
        while (n >= 0) {
            if (nums[n] < max_right) {
                sort(nums.begin() + n + 1, nums.end());
                for (auto iter = nums.begin() + n + 1; iter != nums.end(); iter++) {
                    if (*iter > nums[n]) {
                        int tmp = nums[n];
                        nums[n] = *iter;
                        *iter = tmp;
                        break;
                    }
                }
                break;
            } else if (nums[n] > max_right) {
                max_right = nums[n];
            }
            n --;
        }
        if (n == -1) {
            sort(nums.begin(), nums.end());
        }
    }
};
