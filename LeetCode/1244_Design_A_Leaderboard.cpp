class Leaderboard {
private:
    multiset<int> scores;
    unordered_map<int, multiset<int>::iterator> m;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        int old_score = 0;
        if (m.count(playerId)) {
            old_score = *m[playerId];
            scores.erase(m[playerId]);
            m.erase(playerId);
        }
        auto insert_it = scores.insert(old_score + score);
        m[playerId] = insert_it;
    }
    
    int top(int K) {
        int result = 0;
        auto it = scores.rbegin();
        while (K > 0) {
            result += *it;
            it ++;
            K --;
        }
        return result;
    }
    
    void reset(int playerId) {
        scores.erase(m[playerId]);
        m.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
