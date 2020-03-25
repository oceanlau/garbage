class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }
        int water = 0;
        vector<int> left_limit(height.size(), 0);
        vector<int> right_limit(height.size(), 0);
        left_limit[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            if (height[i] > left_limit[i-1]) {
                left_limit[i] = height[i];
            } else {
                left_limit[i] = left_limit[i-1];
            }
        }
        right_limit[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            if (height[i] > right_limit[i+1]) {
                right_limit[i] = height[i];
            } else {
                right_limit[i] = right_limit[i+1];
            }
            int cur_water = min(left_limit[i], right_limit[i]) - height[i];
            if (cur_water > 0) {
                water += cur_water;
            }
        }
        return water;
    }
};

// two pointer
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }
        int units = 0;
        int left_p = 0;
        int right_p = height.size() - 1;
        int left_max = height[left_p];
        int right_max = height[right_p];
        
        while (left_p != right_p) {
            if (height[left_p] > left_max) {
                left_max = height[left_p];
            }
            if (height[right_p] > right_max) {
                right_max = height[right_p];
            }
            if (left_max <= right_max) {
                units += left_max - height[left_p];
                left_p ++;
            } else {
                units += right_max - height[right_p];
                right_p --;
            }
        }
        
        return units;
    }
};

// too slow
class Solution {
public:
    int trap(vector<int>& height) {
        int units = 0;
        int water_lvl = 0;
        while(true) {
            int tmp_units = 0;
            bool start_fill_flag = false;
            for (int i = 0; i < height.size(); i++) {
                if (height[i] > water_lvl) {
                    if (start_fill_flag) {
                        units += tmp_units;
                        tmp_units = 0;
                    } else {
                        start_fill_flag = true;
                    }
                } else {
                    if (start_fill_flag && height[i] == water_lvl) {
                        tmp_units ++;
                    }
                    height[i] = water_lvl + 1;
                }
            }
            if (!start_fill_flag) {
                break;
            }
            water_lvl ++;
        }
        return units;
    }
};
