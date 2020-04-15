class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums;
        }
        vector<int> ltor = nums;
        vector<int> rtol = nums;
        for (int i = 1; i < ltor.size(); i++) {
            ltor[i] *= ltor[i-1];
        }
        for (int i = rtol.size() - 2; i >= 0; i--) {
            rtol[i] *= rtol[i+1];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                nums[i] = rtol[i + 1];
            } else if (i == nums.size() - 1) {
                nums[i] = ltor[i - 1];
            } else {
                nums[i] = ltor[i - 1] * rtol[i + 1];
            }
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products (nums.size(), 1);
        vector<int> res (nums.size(), 1);
        for (int i = 0; i < nums.size(); i++){
            if (i == 0) {
                products[i] = nums[i];
            } else {
                products[i] = products[i-1] * nums[i];
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                res[i] = products[i - 1];
                products[i] = nums[i];
            } else if (i == 0) {
                res[i] = products[i + 1];
            } else {
                products[i] = products[i+1] * nums[i];
                res[i] = products[i - 1] * products[i + 1];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 1) {
            return {0};
        }
        vector<int> pre_prod = nums;//first use in left to right pre product. then use as result
        // vector<int> post_prod (nums.size(), 1); // use the original nums
        for (int i = 1; i < nums.size() - 1; i++) { // dont need the last one, but it doesnt matter
            pre_prod[i] *= pre_prod[i-1];
        }
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (j == nums.size() - 1) {
                pre_prod[j] = pre_prod[j-1];
            } else if (j == 0) {
                pre_prod[j] = nums[j+1];
            } else {
                nums[j] *= nums[j+1];
                pre_prod[j] = pre_prod[j-1] * nums[j+1];
            }
        }
        return pre_prod;
    }
};
