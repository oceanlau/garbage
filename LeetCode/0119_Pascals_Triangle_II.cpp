class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result (rowIndex + 1, 0);
        result[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            int last = result[0];
            for (int j = 1; j <= i; j++) {
                int tmp = result[j];
                result[j] += last;
                last = tmp;
            }
        }
        return result;
    }
};
