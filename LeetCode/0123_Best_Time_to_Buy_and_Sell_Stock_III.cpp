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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // each index: buy price - prev profit, sell price - (buy price - prev profit)
        // AT MOST: allow buy and sell on the same day (just waste k)
        vector<pair<int, int>> info(2, {INT_MAX, INT_MIN});
        for (const int p : prices) {
            info[0].first = min(info[0].first, p);
            info[0].second = max(info[0].second, p - info[0].first);
            for (int i = 1; i < info.size(); i ++) {
                info[i].first = min(info[i].first, p - info[i - 1].second);
                info[i].second = max(info[i].second, p - info[i].first);
            }
        }
        return info.back().second;
    }
};
