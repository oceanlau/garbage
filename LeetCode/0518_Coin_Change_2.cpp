class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> num_ways_to_amount(amount + 1, 0);
        num_ways_to_amount[0] = 1;
        for (const int c : coins) {
            for (int a = 0; a <= amount; a++) {
                if (a + c > amount) {
                    break;
                }
                num_ways_to_amount[a + c] += num_ways_to_amount[a];
            }
        }
        return num_ways_to_amount[amount];
    }
};
