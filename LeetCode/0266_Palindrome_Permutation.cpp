class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> char_counter(256, 0);
        for (const char c : s) {
            char_counter[c] ++;
        }
        bool one_odd_chance = true;
        for (const int cnt : char_counter) {
            if (cnt % 2 == 1) {
                if (!one_odd_chance) {
                    return false;
                }
                one_odd_chance = false;
            }
        }
        return true;
    }
};
