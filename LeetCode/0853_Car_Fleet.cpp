class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // sort by pos
        // must check from nearest to end till beginning. Cuz Previous cars can't be able to know blockage in the future.
        // check if collision by time spent
        priority_queue<pair<int, double>> pos_time;
        for (int i = 0; i < position.size(); i++) {
            pos_time.push(make_pair(position[i], (target - position[i]) / (double)speed[i]));
        }
        double next_one = -1;
        int cnt = 0;
        while(!pos_time.empty()) {
            double time = pos_time.top().second;
            if (time > next_one) {
                next_one = time;
                cnt ++;
            }
            pos_time.pop();
        }
        return cnt;
    }
};
