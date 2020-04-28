class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int pos = 31;
        int res = 0;
        while (pos >= 0) {
            res += (n & 1) << (pos --);
            n >>= 1;
        }
        return res;
    }
};
