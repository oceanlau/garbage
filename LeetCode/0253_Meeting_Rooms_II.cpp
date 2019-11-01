// PQ of next available end time 75% 100%
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int> next_available_room;
        int min_num = 0;
        for(const vector<int>& interval : intervals) {
            if (next_available_room.size() == 0) {
                min_num = 1;
            } else {
                int next_end_time = -next_available_room.top();
                if (next_end_time <= interval[0]) {
                    next_available_room.pop();
                } else {
                    min_num ++;
                }
            }
            next_available_room.push(-interval[1]);
        }
        return min_num;
    }
};

// Wrong thinking. Sort by begin time doesn't give any guarantee about the end time order.
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int min_rooms = 0;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while (i < intervals.size()) {
            int next_i = intervals.size();
            int cur = 1;
            while (i < intervals.size() - 1 && intervals[i][1] > intervals[i+1][0]) {
                cur ++;
                if (intervals[i][1] < intervals[i+1][1]) {
                    next_i = min(next_i, i+1);
                }
                i++;
            }
            min_rooms = max(min_rooms, cur);
            if (next_i == intervals.size()) {
                i++;
            } else {
                i = next_i;
            }
        }
        return min_rooms;
    }
};
