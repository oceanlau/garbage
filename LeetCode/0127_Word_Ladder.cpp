// Use candidate instead of blacklist. 1 Less find. 5% 43%
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladderLen = 1;
        queue<string> todo;
        todo.push(beginWord);
        unordered_set<string> words(wordList.begin(), wordList.end());
        while (todo.size() != 0) {
            int todo_size = todo.size();
            for (int i = 0; i< todo_size; i++) {
                string middle_man = todo.front();
                todo.pop();
                if (middle_man == endWord) {
                    return ladderLen;
                }
                words.erase(middle_man);
                for (int j = 0; j < middle_man.length(); j++) {
                    char c = middle_man[j];
                    int k = 0;
                    while (k < 26) {
                        middle_man[j] = char(k + 'a');
                        if (words.find(middle_man) != words.end()) {
                            todo.push(middle_man);
                        }
                        k ++;
                    }
                    // Dont forget to put it back!
                    middle_man[j] = c;
                }
            }
            ladderLen ++;
        }
        // Careful, shouldnt go here if found
        return 0;
    }
};


// Time limit exceeds
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladderLen = 1;
        queue<string> todo;
        todo.push(beginWord);
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        while (todo.size() != 0) {
            int todo_size = todo.size();
            for (int i = 0; i< todo_size; i++) {
                string middle_man = todo.front();
                todo.pop();
                if (middle_man == endWord) {
                    return ladderLen;
                }
                for (int j = 0; j < middle_man.length(); j++) {
                    char c = middle_man[j];
                    int k = 0;
                    while (k < 26) {
                        middle_man[j] = char(k + 'a');
                        if (visited.find(middle_man) != visited.end()) {
                            k ++;
                            continue;
                        }
                        if (find(wordList.begin(), wordList.end(), middle_man) != wordList.end()) {
                            todo.push(middle_man);
                            visited[middle_man] = true;
                        }
                        k ++;
                    }
                    // Dont forget to put it back!
                    middle_man[j] = c;
                }
            }
            ladderLen ++;
        }
        // Careful, shouldnt go here if found
        return 0;
    }
};

// For the Facebook problem. Time limit exceeds.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> todo; // Path for the Facebook problem, need the path
        todo.push(vector<string>{beginWord});
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        while (todo.size() != 0) {
            int todo_size = todo.size();
            for (int i = 0; i< todo_size; i++) {
                vector<string> path = todo.front();
                todo.pop();
                string middle_man = path[path.size() - 1];
                if (middle_man == endWord) {
                    return path.size();
                }
                for (int j = 0; j < middle_man.length(); j++) {
                    char c = middle_man[j];
                    int k = 0;
                    while (k < 26) {
                        middle_man[j] = char(k + 'a');
                        if (visited.find(middle_man) != visited.end()) {
                            k ++;
                            continue;
                        }
                        if (find(wordList.begin(), wordList.end(), middle_man) != wordList.end()) {
                            path.push_back(middle_man);
                            todo.push(path);
                            visited[middle_man] = true;
                            path.pop_back();
                        }
                        k ++;
                    }
                    // Dont forget to put it back!
                    middle_man[j] = c;
                }
            }
        }
        return 0;
    }
};
