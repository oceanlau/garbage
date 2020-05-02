class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int mask1 = 1 << 7;
        int mask2 = 1 << 6;
        int cnt = 0;
        for (const int n : data) {
            if (cnt == 0) {
                if ((n & mask1) != 0) {
                    while (n & mask1) {
                        if (++cnt > 4) {
                            return false;
                        }
                        mask1 >>= 1;
                    }
                    if (cnt-- == 1) {
                        return false;
                    }
                    mask1 = 1 << 7;
                }
            } else if ((n & mask1) && ((n & mask2) == 0)){
                cnt --;
            } else {
                return false;
            }
        }
        return cnt == 0;
    }
};
