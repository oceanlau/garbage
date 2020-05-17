class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num_strs;
        for (const int num : nums) {
            num_strs.push_back(to_string(num));
        }
        auto comp = [](const string& l, const string& r) {
            return l + r > r + l;
        };
        sort(num_strs.begin(), num_strs.end(), comp);
        string res = "";
        for (string num_str : num_strs) {
            //careful!
            if (res.length() == 0) {
                int i = 0;
                for (const char c : num_str) {
                    if (c == '0') {
                        i ++;
                    } else {
                        break;
                    }
                }
                num_str = num_str.substr(i);
            }
            res += num_str;
        }
            //careful!
        return res == "" ? "0" : res;
    }
};
