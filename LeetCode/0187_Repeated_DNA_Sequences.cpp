class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> m;
        m['A'] = 0;
        m['C'] = 1;
        m['G'] = 2;
        m['T'] = 3;
        bitset<20> window;
        unordered_set<bitset<20>> seen;
        unordered_set<string> result;
        for (int i = 0; i < 10; i++) {
            window <<= 2;
            window |= m[s[i]];
        }
        seen.insert(window);
        for (int i = 10; i < s.length(); i ++) {
            window <<= 2;
            window |= m[s[i]];
            if (seen.count(window)) {
                // -9, includes i
                result.insert(s.substr(i - 9, 10));
            } else {
                seen.insert(window);
            }
        }
        return vector<string> (result.begin(), result.end());
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<bitset<20>> records;
        unordered_set<string> duplicates;
        vector<char> m(26, 0);
        m['A' - 'A'] = 0;
        m['C' - 'A'] = 1;
        m['G' - 'A'] = 2;
        m['T' - 'A'] = 3;
        bitset<20> rolling_val;
        for (int i = 0; i< s.length(); i++) {
            rolling_val <<= 2;
            rolling_val |= m[s[i] - 'A'];
            if (i >= 9) {
                if (records.count(rolling_val)) {
                    duplicates.insert(s.substr(i - 9, 10));
                } else {
                    records.insert(rolling_val);
                }
            }
        }
        return vector<string> (duplicates.begin(), duplicates.end());
    }
};
