class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost1 = INT_MAX;
        int cost2 = INT_MAX;
        int earn1 = 0;
        int earn2 = 0;
        for (const int price : prices) {
            cost1 = min(cost1, price);
            earn1 = max(earn1, price - cost1);
            cost2 = min(cost2, price - earn1);
            earn2 = max(earn2, price - cost2);
        }
        return earn2;
    }
};
