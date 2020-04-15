class Solution {
public:
    int longestMountain(vector<int>& A) {
        int upwards_started = -1;
        int maxlen = 0;
        int status = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) {
                if (status == 0 || status == -1) {
                    status = 1;
                    upwards_started = i - 1;
                }
            } else if (A[i] < A[i - 1]) {
                if (status == 1 || status == -1) {
                    status = -1;
                    maxlen = max(maxlen, i - upwards_started + 1);
                }
            } else {
                status = 0;
            }
        }
        return maxlen;
    }
};
