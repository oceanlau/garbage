class Solution {
public:
    bool isStrobogrammatic(string num) {
        int l = 0;
        int r = num.size() - 1;
        while (l <= r) {
            char i = num[l++];
            char j = num[r--];
            if ((i == '8' && j == '8') || (i == '6' && j == '9') || (i == '9' && j == '6') || (i == '0' && j == '0') || (i == '1' && j == '1')) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
