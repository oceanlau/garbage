// A bit tricky
class Solution {
public:
    string reorganizeString(string S) {
        int max_rooms = S.length();
        unordered_map<char, int> counter;
        int max_c = 0;
        char max_letter;
        for (const char c : S) {
            counter[c]++;
            if (counter[c] > max_c) {
                max_c = counter[c];
                max_letter = c;
            }            
        }
        if (2 * max_c > max_rooms + 1) {
            return "";
        }
        int idx = 0;
        // For bad case like aab -> baa
        while (counter[max_letter] != 0) {
            S[idx] = max_letter;
            idx +=2 ;
            counter[max_letter]--; 
        }
        // After max letter the rest just put in order
        for (auto iter = counter.begin(); iter != counter.end(); iter++) {
            while (iter->second != 0) {
                if (idx >= max_rooms) {
                    idx = 1;
                }
                S[idx] = iter->first;
                idx +=2 ;
                iter->second --;
            }
        }
        return S;
    }
};
