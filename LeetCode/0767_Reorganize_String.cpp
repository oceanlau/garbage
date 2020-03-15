class Solution {
public:
    string reorganizeString(string S) {
        // put one of the most frequent char at odd poss
        // see is there enough how many spaces left for others
        int total = S.length();
        char most_frequent;
        int most_frequent_num = 0;
        vector<int> letters_cnt(256, 0);
        for (int i = 0; i < S.length(); i++) {
            if (++letters_cnt[S[i]] > most_frequent_num) {
                most_frequent = S[i];
                most_frequent_num = letters_cnt[S[i]];
            }
        }
        //suppose the most frequent one filled the odd poss
        if (total < 2*(most_frequent_num - 1)+1) {
            return "";
        }
        int i = 0;
        // one of the most frequent must be put at pos 0 (odd) to be safe
        // do an odd and an even sweep
        while (letters_cnt[most_frequent] > 0) {
            S[i] = most_frequent;
            letters_cnt[most_frequent] --;
            i += 2;
        }
        for (int j = 0; j < 256; j++) {
            if (letters_cnt[j] == 0) {
                continue;
            }
            while (letters_cnt[j] > 0) {
                //even sweep
                if (i >= S.length()) {
                    i = 1;
                }
                S[i] = (char)j;
                letters_cnt[j] --;
                i += 2;
            }
        }
        return S;
    }
};

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
