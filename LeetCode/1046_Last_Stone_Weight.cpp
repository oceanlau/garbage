class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> largest(stones.begin(), stones.end());
        while (largest.size() > 1) {
            int y = largest.top();
            largest.pop();
            int x = largest.top();
            largest.pop();
            if (x < y) {
                largest.push(y - x);
            }
        }
        if (largest.empty()) {
            return 0;
        }
        return largest.top();
    }
};
