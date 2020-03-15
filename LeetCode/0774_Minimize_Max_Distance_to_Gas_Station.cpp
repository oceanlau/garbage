class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double Dl = 0;
        double Dr = stations[stations.size() - 1] - stations[0];
        while (Dr - Dl > 1e-6) {
            double mid = Dl + (Dr - Dl) / 2;
            int required = 0;
            for (int i = 0; i < stations.size() - 1; i++) {
                required += ceil((stations[i+1] - stations[i]) / mid - 1);
            }
            if (required > K) {
                Dl = mid;
            } else {
                Dr = mid;
            }
        }
        return Dl;
    }
};
