class Solution {
public:
    string removeDuplicates(string s) {
        stack<pair<char, int>> char_cnt;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            // continue the streak
            if (char_cnt.empty()) {
                char_cnt.emplace(c, 1);
            } else if (c == char_cnt.top().first) {
                char_cnt.top().second ++; 
            } else {
                if (!char_cnt.empty() && char_cnt.top().second > 3) {
                    char_cnt.pop();
                    i --;
                } else {
                    char_cnt.emplace(c, 1);
                }
            }
        }
        if (!char_cnt.empty() && char_cnt.top().second > 3) {
            char_cnt.pop();
        }
        string res = "";
        while (!char_cnt.empty()) {
            while (char_cnt.top().second > 0) {
                char_cnt.top.second --;
                res = char_cnt.top().first + res;
            }
            char_cnt.pop();
        }
        return res;
    }

    string removeDuplicatesII(string s) {
        // recursion, all possible comb
        // time complexity?
        // return if nothing to remove
        // remove left most one, recur on this func and save to left
        // remove right most one, recur on this func and save to right
        // return short one of left and right
    }
};
