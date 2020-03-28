class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minimum = INT_MAX;
        int second_minimum = INT_MAX;
        for (const int n : nums) {
            // careful = here. 1111111 seq
            if (n <= minimum) {
                minimum = n;
            } else if (n <= second_minimum) {
                second_minimum = n;
            } else {
                return true;
            }
        }
        return false;
    }
};
