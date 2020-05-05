class Solution {
public:
    int findComplement(int num) {
        //remove leading zeroes by getting a mask
        int tmp = num;
        int mask = 1;
        tmp >>= 1;
        while (tmp != 0) {
            tmp >>= 1;
            mask <<= 1;
            mask |= 1;
        }
        return ~num & mask;
    }
};
