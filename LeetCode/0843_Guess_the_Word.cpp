/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    int get_overlap(string w1, string w2) {
        int overlap = 0;
        for (int i = 0; i < 6; i++) {
            if (w1[i] == w2[i]) {
                overlap ++;
            }
        }
        return overlap;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        //find max overlap word
        vector<vector<int>> ccnt(6, vector<int>(26, 0));
        for (const string& w : wordlist) {
            for (int i = 0; i < w.length(); i++) {
                ccnt[i][w[i] - 'a'] ++;
            }
        }
        string guess = "";
        int max_score = 0;
        for (const string& w : wordlist) {
            int score = 0;
            for (int i = 0; i < w.length(); i++) {
                score += ccnt[i][w[i] - 'a'];
            }
            if (score > max_score) {
                max_score = score;
                guess = w;
            }
        }
        int overlap = 0;
        vector<string> wl = wordlist;
        while (true) {
            vector<string> tmp_wl = wl;
            wl.clear();
            overlap = master.guess(guess);
            if (overlap == 6) {
                return;
            }
            for (const string& w : tmp_wl) {
                if (w != guess && overlap == get_overlap(guess, w)) {
                    wl.push_back(w);
                }
            }
            guess = wl[0];
        }
    }
};
