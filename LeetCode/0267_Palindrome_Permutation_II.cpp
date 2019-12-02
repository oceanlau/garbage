class Solution {
private:
    void _dfs(unordered_map<char, int>& counter, string s, int n, string& odd_char, vector<string>& res) {
        if (s.length() == n) {
            string other_half = s;
            reverse(other_half.begin(), other_half.end());
            res.push_back(s + odd_char + other_half);
            return;
        }
        
        // dont forget &
        for (auto& kv : counter) {
            if (kv.second > 1) {
                kv.second -= 2;
                _dfs(counter, s + kv.first, n, odd_char, res);
                kv.second += 2;
            }
        }
        
    }
public:
    vector<string> generatePalindromes(string s) {
        if (s.length() < 2) {
            return vector<string> {s};
        }
        //build char counter map. check if there is a valid parlindrome
        unordered_map<char, int> counter;
        int odd_char_cnt = 0;
        for (const char& c : s) {
            counter[c]++;
            if (counter[c] % 2 == 1) {
                odd_char_cnt ++;
            } else {
                odd_char_cnt --;
            }
        }
        int half_size = s.size() / 2;
        string odd_char = "";
        if (odd_char_cnt > 1) {
            return {};
        } else if (odd_char_cnt == 1) {
            for(const auto& kv : counter) {
                if (kv.second % 2 == 1) {
                    odd_char = kv.first;
                    break;
                }
            }
        }
        //build half of the parlindrome
        //build the other half
        vector<string> res;
        _dfs(counter, "", half_size, odd_char, res);
        return res;
    }
};
