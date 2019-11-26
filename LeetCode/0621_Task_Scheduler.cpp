class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //max freq task first:
        //A -- n -- A -- n -- A B
        //countOfMaxFreq + countOfTaskTypeWithSameMaxFreq +
        //max( (countOfMaxFreq-1)*n, remainingTaskCount ) // include other taskTypeWithSameMaxFreq, -1 each
        unordered_map<char, int> taskFreq;
        int maxFreq = 0;
        char taskWithMaxFreq;
        for(const char task : tasks) {
            if (++taskFreq[task] > maxFreq) {
                maxFreq = taskFreq[task];
                taskWithMaxFreq = task;
            }
        }
        taskFreq[taskWithMaxFreq] = 0;
        int sameMaxFreq = 0;
        int remaining = 0;
        for(auto kv : taskFreq) {
            if (kv.second == maxFreq) {
                sameMaxFreq++;
                remaining += (kv.second - 1);
            } else {
                remaining += kv.second;
            }
        }
        return maxFreq + sameMaxFreq + max( (maxFreq - 1) * n, remaining );
    }
};

//speed2, no faster than speed 1
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_count = 0;
        unordered_map<char, int> char_count_map;
        for (auto& c : tasks) {
            char_count_map[c]++;
            max_count = max(max_count, char_count_map[c]);
        }
        
        int high_freq_tasks_type = 0;
        for (auto& item : char_count_map) {
            if (item.second == max_count) {
                high_freq_tasks_type ++;
            }
        }
        // or we could say, with idle (if no idle, then intervals would be the len of tasks)
        int min_accommdation_for_hft = 1 + (n + 1) * (max_count - 1);
        
        if (n > (high_freq_tasks_type-1)) {
            min_accommdation_for_hft += high_freq_tasks_type-1; // trailing high_freq_tasks
        }
        
        return max(min_accommdation_for_hft, (int)tasks.size());
        
    }
};


// speed1 60.5% 93.6%
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_count = 0;
        unordered_map<char, int> char_count_map;
        for (auto iter = tasks.begin(); iter != tasks.end(); iter++) {
            char_count_map[*iter]++;
            max_count = max(max_count, char_count_map[*iter]);
        }
        
        int high_freq_tasks_type = 0;
        for (auto iter = char_count_map.begin(); iter != char_count_map.end(); iter++) {
            if (iter->second == max_count) {
                high_freq_tasks_type ++;
            }
        }
        // or we could say, with idle (if no idle, then intervals would be the len of tasks)
        int min_accommdation_for_hft = 1 + (n + 1) * (max_count - 1);
        
        if (n > (high_freq_tasks_type-1)) {
            min_accommdation_for_hft += high_freq_tasks_type-1; // trailing high_freq_tasks
        }
        
        return max(min_accommdation_for_hft, (int)tasks.size());
        
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_count = 0;
        unordered_map<char, int> char_count_map;
        for (auto iter = tasks.begin(); iter != tasks.end(); iter++) {
            if (char_count_map.find(*iter) != char_count_map.end()) {
                char_count_map[*iter]++;
                max_count = max(max_count, char_count_map[*iter]);
            } else {
                char_count_map[*iter] = 1;
            }
        }
        
        int high_freq_tasks_type = 0;
        for (auto iter = char_count_map.begin(); iter != char_count_map.end(); iter++) {
            if (iter->second == max_count) {
                high_freq_tasks_type ++;
            }
        }
        // or we could say, with idle (if no idle, then intervals would be the len of tasks)
        int min_accommdation_for_hft = 1 + (n + 1) * (max_count - 1);
        
        if (n > (high_freq_tasks_type-1)) {
            min_accommdation_for_hft += high_freq_tasks_type-1; // trailing high_freq_tasks
        }
        
        return max(min_accommdation_for_hft, (int)tasks.size());
        
    }
};
