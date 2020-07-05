class UndergroundSystem {
private:
    // start_end -> {sum of time, n}
    unordered_map<string, pair<int, int>> time_agg;
    // id -> {start, start_time}
    unordered_map<int, pair<string, int>> start_info;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        start_info[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        int duration = t - start_info[id].second;
        string route = start_info[id].first + '_' + stationName;
        if (time_agg.count(route)) {
            time_agg[route].second ++;
            time_agg[route].first += duration;
        } else {
            time_agg[route] = make_pair(duration, 1);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto time_info = time_agg[startStation + '_' + endStation];
        return time_info.first / (double)time_info.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
