class Solution {
public:
    struct Log {
        int id;
        string type;
        int time;
    };
    Log process_log(string line) {
        int colon1 = line.find(':');
        int colon2 = line.find(':', colon1+1);
        return Log{stoi(line.substr(0, colon1)), line.substr(colon1+1, colon2-colon1-1), stoi(line.substr(colon2+1))};
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int,int>> func_stack;// of id and start time
        for (int i = 0; i < logs.size(); i++) {
            Log log = process_log(logs[i]);
            if (log.type == "start") {
                func_stack.push(make_pair(log.id, log.time));
            } else {
                int id = func_stack.top().first;
                int current_time = log.time - func_stack.top().second + 1;
                func_stack.pop();
                res[id] += current_time;
                //tricky here! subtract in advance
                if (func_stack.size() > 0) {
                    res[func_stack.top().first] -= current_time;
                }
            }
        }
        return res;
    }
};

//wrong thinking. Could be 0 - 1 - 1 --- 2 - 2 - 0. Cant use a single previous_func_time var
//solution: when one end, substract its time from parent function (func_stack.top())
class Solution {
public:
    struct Log {
        int id;
        string type;
        int time;
    };
    Log process_log(string line) {
        int colon1 = line.find(':');
        int colon2 = line.find(':', colon1+1);
        return Log{stoi(line.substr(0, colon1)), line.substr(colon1+1, colon2-colon1-1), stoi(line.substr(colon2+1))};
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int,int>> func_stack;// of id and start time
        int previous_func_time = 0;
        for (int i = 0; i < logs.size(); i++) {
            Log log = process_log(logs[i]);
            if (log.type == "start") {
                func_stack.push(make_pair(log.id, log.time));
            } else {
                int id = func_stack.top().first;
                int start_time = func_stack.top().second;
                func_stack.pop();
                res[id] += log.time - start_time + 1 - previous_func_time;
                previous_func_time = log.time - start_time + 1;
            }
        }
        return res;
    }
};
