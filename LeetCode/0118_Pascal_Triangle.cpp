class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows, vector<int>(1, 1));
        
        for (int i = 1; i <= numRows; i ++) {
            pascal[i-1].resize(i);
            pascal[i-1][0] = 1;
            pascal[i-1][i-1] = 1;
            for (int j = 2; j <= i; j ++) {
                pascal[i-1][j-1] = pascal[i-2][j-2];
                if (j-1 <= i-1-1) {
                    pascal[i-1][j-1] += pascal[i-2][j-1];
                }
            }
        }
        
        return pascal;
    }
};
