class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<int> e1 = arr1;
        vector<int> e2 = arr1;
        vector<int> e3 = arr1;
        vector<int> e4 = arr1;
        for (int i = 0; i < arr1.size(); i++) {
            e1[i] = arr1[i] + arr2[i] + i;
            e2[i] = arr1[i] + arr2[i] - i;
            e3[i] = arr1[i] - arr2[i] + i;
            e4[i] = arr1[i] - arr2[i] - i;
        }
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int max4 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int min3 = INT_MAX;
        int min4 = INT_MAX;
        for (int i = 0; i < e1.size(); i++) {
            max1 = max(max1, e1[i]);
            min1 = min(min1, e1[i]);
            max2 = max(max2, e2[i]);
            min2 = min(min2, e2[i]);
            max3 = max(max3, e3[i]);
            min3 = min(min3, e3[i]);
            max4 = max(max4, e4[i]);
            min4 = min(min4, e4[i]);
        }
        return max(max(max1 - min1, max2 - min2), max(max3 - min3, max4 - min4));
    }
};
