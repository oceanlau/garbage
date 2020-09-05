class Solution {
private:
    unordered_map<string, vector<int>> cache;
public:
    vector<int> diffWaysToCompute(string input) {
        if (cache.count(input)) {
            return cache[input];
        }
        cache[input] = {};
        for (int i = 0; i < input.length(); i ++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (const int l : left) {
                    for (const int r : right) {
                        if (input[i] == '+') {
                            cache[input].push_back(l + r);
                        }
                        if (input[i] == '-') {
                            cache[input].push_back(l - r);
                        }
                        if (input[i] == '*') {
                            cache[input].push_back(l * r);
                        }
                    }
                }
            }
        }
        if (cache[input].empty()) {
            cache[input].push_back(stoi(input));
        }
        return cache[input];
    }
};
