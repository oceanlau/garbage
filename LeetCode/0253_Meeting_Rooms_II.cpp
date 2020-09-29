class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> times;
        for (const vector<int>& interval : intervals) {
            times.emplace_back(interval[0], 1);
            times.emplace_back(interval[1], -1);
        }
        int needed = 0;
        int current = 0;
        sort(times.begin(), times.end());
        for (const pair<int, int> p : times) {
            current += p.second;
            needed = max(needed, current);
        }
        return needed;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int rooms = 0;
        // turn to min heap
        auto comp = [](const vector<int>& l, const vector<int>& r){
            return l[1] > r[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> releases(comp);
        sort(intervals.begin(), intervals.end());
        for (const vector<int>& interval : intervals) {
            while (!releases.empty() && releases.top()[1] <= interval[0]) {
                releases.pop();
            }
            releases.push(interval);
            rooms = max(rooms, (int)releases.size());
        }
        return rooms;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> sessions;
        int rooms = 0;
        for (int i = 0; i < intervals.size(); i++) {
            while (sessions.size() != 0 && intervals[i][0] >= sessions.top()) {
                sessions.pop();
            }
            sessions.push(intervals[i][1]);
            rooms = max(rooms, (int)sessions.size());
        }
        return rooms;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // walk through all meetings, push each into min heap (by end time)
        // compare each start time with end times in heap. clear all previous meetings
        // max heap size is the answer
        priority_queue<int> endtimes;
        int ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            while (!endtimes.empty()) {
                if (-endtimes.top() <= intervals[i][0]) {
                    endtimes.pop();
                } else {
                    break;
                }
            }
            endtimes.push(-intervals[i][1]);
            ans = max(ans, (int)endtimes.size());
        }
        return ans;
    }
};

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
