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
