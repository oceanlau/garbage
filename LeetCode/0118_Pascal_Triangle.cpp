class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return {};
        }
        vector<vector<int>> pascal {{1}};
        int cnt = 2;
        while (cnt <= numRows) {
            const vector<int>& last_row = pascal[cnt - 2];
            vector<int> row (cnt, 1);
            for (int i = 0; i < cnt; i++) {
                if (i - 1 < 0) {
                    row[i] = last_row[i];
                } else if (i >= last_row.size()) {
                    row[i] = last_row[i - 1];
                } else {
                    row[i] = last_row[i] + last_row[i - 1];
                }
            }
            pascal.push_back(row);
            cnt ++;
        }
        return pascal;
    }
};

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
