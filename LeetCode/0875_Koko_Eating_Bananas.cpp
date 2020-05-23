class Solution {
private:
    int _canFinish(vector<int>& piles, int H, int speed) {
        int time = 0;
        for (const int p : piles) {
            time += p / speed;
            if (p % speed > 0) {
                time += 1;
            }
        }
        return time <= H;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (_canFinish(piles, H, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (_canFinish(piles, H, l)) {
            return l;
        }
        return r;
    }
};
