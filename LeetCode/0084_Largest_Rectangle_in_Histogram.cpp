//stack, 51% 69%
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> lowest_stack;
        int largest = 0;
        int lowest_idx = 0;
        int tmp_area = 0;
        int heights_size = heights.size();
        for(int i = 0; i < heights_size;) {
            if (lowest_stack.size() == 0 || heights[i] >= heights[lowest_stack.top()]) {
                lowest_stack.push(i++);
            } else {
                lowest_idx = lowest_stack.top();
                lowest_stack.pop();
                tmp_area = heights[lowest_idx] * (lowest_stack.size() == 0 ? i : i - lowest_stack.top() - 1);
                largest = max(largest, tmp_area);
            }
        }
        while (lowest_stack.size() != 0) {
            lowest_idx = lowest_stack.top();
            lowest_stack.pop();
            tmp_area = heights[lowest_idx] * (lowest_stack.size() == 0 ? heights_size : heights_size - lowest_stack.top() - 1);
            largest = max(largest, tmp_area);
        }
        return largest;
    }
};
