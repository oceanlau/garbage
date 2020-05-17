class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        unordered_set<char> v {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (i < j) {
            while (i < j && !v.count(s[i])) {
                i ++;
            }
            while (i < j && !v.count(s[j])) {
                j --;
            }
            if (i < j) {
                swap(s[i], s[j]);
                i ++;
                j --;
            }
        }
        return s;
    }
};
