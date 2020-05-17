class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> bucket(26, 0);
        for (const char c : T) {
            bucket[c - 'a'] ++;
        }
        int i = 0;
        for (const char c : S) {
            while (bucket[c - 'a']) {
                T[i++] = c;
                bucket[c - 'a'] --;
            }
        }
        for (int j = 0; j < 26; j++) {
            while (bucket[j]) {
                T[i++] = 'a' + j;
                bucket[j] --;
            }
        }
        return T;
    }
};
