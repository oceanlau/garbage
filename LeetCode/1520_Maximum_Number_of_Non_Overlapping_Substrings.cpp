class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int, int>> start_end(26, {s.length(), -1});
        for (int i = 0; i < s.length(); i++) {
            start_end[s[i] - 'a'].first = min(start_end[s[i] - 'a'].first, i);
            start_end[s[i] - 'a'].second = max(start_end[s[i] - 'a'].second, i);
        }
        vector<pair<int, int>> candidates;
        for (int i = 0; i < s.length(); i++) {
            if (i == start_end[s[i] - 'a'].first) {
                int right = start_end[s[i] - 'a'].second;
                for (int j = i + 1; j <= right; j++) {
                    if (start_end[s[j] - 'a'].first < i) {
                        right = -1;
                        break;
                    }
                    right = max(right, start_end[s[j] - 'a'].second);
                }
                if (right != -1) {
                    candidates.emplace_back(i, right);
                }
            }
        }
        if (candidates.empty()) {
            return {};
        }
        vector<string> result;
        int left = candidates[0].first;
        int right = candidates[0].second;
        for (int i = 1; i < candidates.size(); i ++) {
            if (candidates[i].first > right) {
                result.push_back(s.substr(left, right - left + 1));
                left = candidates[i].first;
                right = candidates[i].second;
            } else {
                if (candidates[i].second <= right) {
                    left = candidates[i].first;
                    right = candidates[i].second;
                }
            }
        }
        result.push_back(s.substr(left, right - left + 1));
        return result;
    }
};
