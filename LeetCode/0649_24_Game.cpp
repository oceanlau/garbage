class Solution {
private:
    bool combine(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24) < 1e-4;
        }
        // pick 2
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                double a = nums[i];
                double b = nums[j];
                vector<double> combined {a + b, a - b, b - a, a * b};
                if (a != 0) {
                    combined.push_back(b / a);
                }
                if (b != 0) {
                    combined.push_back(a / b);
                }
                
                vector<double> next_nums;
                // remaining numbers
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        next_nums.push_back(nums[k]);
                    }
                }
                //reduce into next step
                for (int k = 0; k < combined.size(); k++) {
                    next_nums.push_back(combined[k]);
                    if (combine(next_nums)) {
                        return true;
                    }
                    next_nums.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> next_nums {nums[0] * 1.0, nums[1] * 1.0, nums[2] * 1.0, nums[3] * 1.0};
        return combine(next_nums);
    }
};
