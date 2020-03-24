class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxarea = 0;
        while (i != j) {
            int area = (j - i) * min(height[i], height[j]);
            if (area > maxarea) {
                maxarea = area;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxarea;
    }
};


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int w = 0;
        int max_area = 0;
        int tmp_area = 0;
        while (j - i > 0) {
            w = j - i;
            if(height[i] > height[j]) {
                tmp_area = height[j] * w;
                j --;
            } else {
                tmp_area = height[i] * w;
                i ++;
            }
            if(tmp_area > max_area) {
                max_area = tmp_area;
            }
        }
        return max_area;
        
    }
};
