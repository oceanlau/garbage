class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n+1, 0);
        for (const int cita : citations) {
            if (cita >= n) {
                bucket[n]++;
            } else {
                bucket[cita]++;
            }
        }
        int cnt = 0;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            cnt += bucket[i];
            if (cnt >= i) {
                return i;
            }
        }
        return 0;
    }
};
