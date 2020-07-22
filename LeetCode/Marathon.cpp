struct Runner {
    int id;
    string name;
};
struct CP {
    int distance;
    int id;
}

class Leaderboard {
private:
    vector<list<int>> bucket_runner;
    unordered_map<int, int> cp_bucket;
public:
    Leaderboard (vector<CP> checkpoints) {
        auto comp = [](const CP& l, const CP& r) {
            return l.distance < r.distance;
        };
        sort(checkpoints.begin(), checkpoints.end(), comp);
        buckets.reserve(checkpoints.size());
        for (int i = 0; i < checkpoints.size(); i++) {
            cp_bucket[checkpoints[i].id] = i;
        }

}
