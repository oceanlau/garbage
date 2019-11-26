class Solution {
private:
    int _count(int num) {
        int sum = 0;
        for (int i = 3; i<= num; i++) {
            sum += (num - i + 1);
        }
        return sum;
    }
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i = 0;
        int j = 0;
        int sum = 0;
        while (j < A.size()) {
            if (j - i > 1 && A[j] - A[j - 1] != A[j - 1] - A[j - 2]) {
                sum += _count(j - i);
                //consider 1,2,3,4,6,8. 4 need to be considered in the next window
                i = j - 1;
            }
            j ++;
        }
        if (--j > 1 && A[j] - A[j - 1] == A[j - 1] - A[j - 2]) {
            sum += _count(j - i + 1);
        }
        return sum;
    }
};
