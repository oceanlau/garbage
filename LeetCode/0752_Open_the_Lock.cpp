class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> q_set1 {"0000"};
        unordered_set<string> q_set2 {target};
        unordered_set<string> dd(deadends.begin(), deadends.end());
        if (dd.count("0000") || dd.count(target)) {
            return -1;
        }
        if (target == "0000") {
            return 0;
        }
        int steps = 0;
        unordered_set<string> visited {"0000", target};
        while (!q_set1.empty() && !q_set2.empty()) {
            if (q_set1.size() > q_set2.size()) {
                swap(q_set1, q_set2);
            }
            unordered_set<string> next;
            steps++;
            for (auto it = q_set1.begin(); it != q_set1.end(); it ++) {
                for (int i = 0; i < 4; i++) {
                    string new_word = *it;
                    if (new_word[i] == '9') {
                        new_word[i] = '0';
                    } else {
                        new_word[i] ++;
                    }
                    if (q_set2.count(new_word)) {
                        return steps;
                    }
                    if (!visited.count(new_word) && !dd.count(new_word)) {
                        visited.insert(new_word);
                        next.insert(new_word);
                    }
                    new_word = *it;
                    if (new_word[i] == '0') {
                        new_word[i] = '9';
                    } else {
                        new_word[i] --;
                    }
                    if (q_set2.count(new_word)) {
                        return steps;
                    }
                    if (!visited.count(new_word) && !dd.count(new_word)) {
                        visited.insert(new_word);
                        next.insert(new_word);
                    }
                }
            }
            q_set1 = next;
        }
        return -1;
    }
};
