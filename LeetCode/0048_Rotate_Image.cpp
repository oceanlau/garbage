class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int layer_cnt = matrix.size();
        for (int layer = 0; layer_cnt > 0; layer++) {
            layer_cnt -= 2;
            int edge = matrix.size() - layer - 1;
            int idx = 0;
            for (int i = layer; i < edge; i++) {
                swap(matrix[i][layer], matrix[edge][i]);
                swap(matrix[edge][i], matrix[edge - idx][edge]);
                swap(matrix[edge - idx][edge], matrix[layer][edge - idx]);
                idx ++;
            }
        }
    }
};
