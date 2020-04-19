class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> result_idxs;
        for (int i = 0; i < deck.size(); i ++) {
            result_idxs.push_back(i);
        }
        sort(deck.begin(), deck.end());
        vector<int> result(deck.size(), 0);
        int i = 0;
        while (!result_idxs.empty()) {
            int idx = result_idxs.front();
            result_idxs.pop_front();
            result[idx] = deck[i++];
            if (!result_idxs.empty()) {
                idx = result_idxs.front();
                result_idxs.pop_front();
                result_idxs.push_back(idx);
            }
        }
        return result;
    }
};
