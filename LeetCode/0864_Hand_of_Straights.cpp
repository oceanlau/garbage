class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> cards_cnt;
        for (const int& card : hand) {
            cards_cnt[card] ++;
        }
        for (auto& p : cards_cnt) {
            if (p.second == 0) {
                continue;
            }
            for (int i = 1; i < W; i++) {
                if (!cards_cnt.count(p.first + i) || cards_cnt[p.first + i] < p.second) {
                    return false;
                }
                cards_cnt[p.first + i] -= p.second;
            }
            p.second = 0;
        }
        return true;
    }
};
