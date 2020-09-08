class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i ++) {
            res += (n & 1);
            n >>= 1;
            if (i < 31) {
                res <<= 1;
            }
        }
        return res;
    }
};

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
