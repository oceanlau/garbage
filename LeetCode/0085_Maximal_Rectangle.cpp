class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if (h == 0) {
            return 0;
        }
        int w = matrix[0].size();
        for (int j = 0; j < w; j++) {
            for (int i = 1; i < h; i++) {
                if (matrix[i][j] > '0') {
                    matrix[i][j] += matrix[i-1][j] - '0';
                }
            }
        }
        // mono inc stack to find max area base on each row
        int maxsize = 0;
        for (int i = 0; i < h; i++) {
            stack<int> leftbounds;
            for (int j = 0; j <= w; j++) {
                int cur_height = 0;
                if (j < w) {
                    cur_height = matrix[i][j] - '0';
                }
                while (!leftbounds.empty() && cur_height <= matrix[i][leftbounds.top()] - '0') {
                    int last_height = matrix[i][leftbounds.top()] - '0';
                    leftbounds.pop();
                    //careful!
                    int left = 0;
                    if (!leftbounds.empty()) {
                        //careful!
                        left = leftbounds.top() + 1;
                    }
                    maxsize = max(maxsize, (j - left) * last_height);
                }
                leftbounds.push(j);
            }
        }
        return maxsize;
    }
};

//94% 55%
class Solution {
private:
    int _maximalHist(vector<char>& heights) {
        int end = heights.size();
        stack<int> shorter;
        int maximal = 0;
        for(int i = 0; i <= end; i++) {
            while ( !shorter.empty() && (i == end || heights[i] < heights[shorter.top()]) ){
                int height = heights[shorter.top()];
                shorter.pop();
                int width = 0;
                if (shorter.empty()) {
                    width = i;
                } else {
                    width = i - shorter.top() - 1;
                }
                maximal = max(maximal, width*height);
            }
            if (i != end) {
                shorter.push(i);
            }
        }
        return maximal;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if (h == 0) {
            return 0;
        }
        int w = matrix[0].size();
        int maximal = 0;
        // Lets break some things!
        //vector<vector<int>> heights(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == '1') {
                    if (i - 1 < 0) {
                        matrix[i][j] = 1;
                    } else {
                        matrix[i][j] = matrix[i-1][j] + 1;
                    }
                } else {
                    matrix[i][j] = 0;
                }
            }
            maximal = max(maximal, _maximalHist(matrix[i]));
        }
        return maximal;
    }
};

// 5% 5%. No need compute every cell. Just once per row!
class Solution {
private:
    int _maximalHist(vector<char>& heights, int end) {
        stack<int> shorter;
        int maximal = 0;
        for(int i = 0; i <= end + 1; i++) {
            while ( !shorter.empty() && (i == end + 1 || heights[i] < heights[shorter.top()]) ){
                int height = heights[shorter.top()];
                shorter.pop();
                int width = 0;
                if (shorter.empty()) {
                    width = i;
                } else {
                    width = i - shorter.top() - 1;
                }
                maximal = max(maximal, width*height);
            }
            if (i != end + 1) {
                shorter.push(i);
            }
        }
        return maximal;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if (h == 0) {
            return 0;
        }
        int w = matrix[0].size();
        int maximal = 0;
        // Lets break some things!
        //vector<vector<int>> heights(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == '1') {
                    if (i - 1 < 0) {
                        matrix[i][j] = 1;
                    } else {
                        matrix[i][j] = matrix[i-1][j] + 1;
                    }
                    maximal = max(maximal, _maximalHist(matrix[i], j));
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        return maximal;
    }
};
