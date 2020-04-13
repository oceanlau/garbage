class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int canbuy = 0;
        int hold = -prices[0];
        int cooldown = 0;
        for (int i = 1; i < prices.size(); i++) {
            int last_canbuy = canbuy;
            int last_hold = hold;
            int last_cooldown = cooldown;
            canbuy = max(last_canbuy, last_cooldown);
            hold = max(last_hold, last_canbuy - prices[i]);
            cooldown = last_hold + prices[i];
        }
        return max(canbuy, cooldown);
    }
};
