class ExamRoom {
private:
    set<int> seated;
    int n = 0;
public:
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if (seated.empty()) {
            seated.insert(0);
            return 0;
        }/* else if (seated.size() == 1){
            int pos = *seated.begin();
            if (pos - 1 <= n - 1 - pos - 1) {
                seated.insert(0);
                return 0;
            } else {
                seated.insert(n - 1);
                return n - 1;
            }
        }*/ else {
            int candidate_pos = -1;
            int distance = -1;
            auto it = seated.begin();
            if (*it != 0) {
                candidate_pos = 0;
                distance = *it - 1;
            }
            auto lastit = it++;
            while(it != seated.end()) {
                int cur_dist = *it - *lastit;
                if (cur_dist > 1) {
                    cur_dist = (cur_dist - 2) / 2;
                    if (cur_dist > distance) {
                        distance = cur_dist;
                        candidate_pos = *lastit + cur_dist + 1;
                    }
                }
                lastit ++;
                it ++;
            }
            if (*lastit != n - 1) {
                int cur_dist = n - 1 - *lastit - 1;
                if (cur_dist > distance) {
                    //distance = cur_dist;
                    //candidate_pos = *lastit + cur_dist + 1;
                    candidate_pos = n - 1;
                }
            }
            seated.insert(candidate_pos);
            return candidate_pos;
        }
    }
    
    void leave(int p) {
        seated.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
