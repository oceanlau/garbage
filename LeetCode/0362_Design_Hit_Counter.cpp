class HitCounter {
private:
    int _cnt = 0;
    list<pair<int, int>> buckets;
public:
    /** Initialize your data structure here. */
    HitCounter() {
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while (!buckets.empty() && buckets.front().first <= timestamp - 300) {
            _cnt -= buckets.front().second;
            buckets.pop_front();
        }
        if (!buckets.empty() && buckets.back().first == timestamp) {
            buckets.back().second ++;
        } else {
            buckets.emplace_back(timestamp, 1);
        }
        _cnt ++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!buckets.empty() && buckets.front().first <= timestamp - 300) {
            _cnt -= buckets.front().second;
            buckets.pop_front();
        }
        return _cnt;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
