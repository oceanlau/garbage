// 92% 100%
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& ltrip, const vector<int>& rtrip) {
            return ltrip[1] < rtrip[1];
        });
        auto comp = [](const vector<int>& ltrip, const vector<int>& rtrip) {
            return ltrip[2] > rtrip[2];
        };
        //no &comp here.
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> next_seats_available(comp);
        for (const vector<int>& trip : trips) {
            // Not if! While here! Could release multiple seats.
            while (!next_seats_available.empty() && trip[1] >= next_seats_available.top()[2]) {
                capacity += next_seats_available.top()[0];
                next_seats_available.pop();
            }
            next_seats_available.push(trip);
            capacity -= trip[0];
            if (capacity < 0) {
                return false;
            }
        }
        return true;
    }
};
