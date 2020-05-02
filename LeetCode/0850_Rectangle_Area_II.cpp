class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int m = pow(10, 9) + 7;
        // rect can be very large. so events cannot be indexed by y 0 - max
        // instead are the 2x the size of rects.size() (open and close event)
        
        //cannot use set for events and intervals, maybe dupe!
        vector<vector<int>> events;
        map<pair<int, int>, int> intervals;
        for (const vector<int>& rect : rectangles) {
            events.push_back({rect[1], 0, rect[0], rect[2]}); // open
            events.push_back({rect[3], 1, rect[0], rect[2]}); // close
        }
        sort(events.begin(), events.end());
        int ans = 0;
        auto e_it = events.begin();
        int last_y = e_it->at(0);
        int y = -1;
        while (e_it != events.end()) {
            while (e_it != events.end() && e_it->at(0) == last_y) {
                pair<int, int> range = make_pair(e_it->at(2), e_it->at(3));
                if (e_it->at(1) == 0) {
                    intervals[range] ++;
                } else {
                    if (--intervals[range] == 0) {
                        intervals.erase(range);
                    }
                }
                e_it ++;
            }
            
            if (e_it != events.end()) {
                y = e_it->at(0);
            }
            
            if (!intervals.empty()) { // also means y existsk
                auto cur = intervals.begin();
                int last_x0 = cur->first.first;
                int last_x1 = cur->first.second;
                cur ++;
                while (cur != intervals.end()) {
                    int x0 = cur->first.first;
                    int x1 = cur->first.second;
                    if (x0 > last_x1) {
                        ans += (long long)(y - last_y) % m * (last_x1 - last_x0) % m;
                        ans %= m;
                        last_x0 = x0;
                        last_x1 = x1;
                    } else {
                        last_x1 = max(x1, last_x1);
                    }
                    cur ++;
                }
                ans += (long long)(y - last_y) % m * (last_x1 - last_x0) % m;
                ans %= m;
            }
            
            last_y = y;
        }
        return ans % m;
    }
};
