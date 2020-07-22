class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        int most_frequent = 0;
        int most_frequent_freq = 0;
        for (const int b : barcodes) {
            if (++freq[b] > most_frequent_freq) {
                most_frequent = b;
                most_frequent_freq = freq[b];
            }
        }
        int i  = 0;
        while (i < barcodes.size()) {
            int to_fill = freq.begin()->first;
            if (freq.count(most_frequent)) {
                to_fill = most_frequent;
            }
            barcodes[i] = to_fill;
            if (-- freq[to_fill] == 0) {
                freq.erase(to_fill);
            }
            i += 2;
        }
        i = 1;
        while (i < barcodes.size()) {
            int to_fill = freq.begin()->first;
            if (freq.count(most_frequent)) {
                to_fill = most_frequent;
            }
            barcodes[i] = to_fill;
            if (-- freq[to_fill] == 0) {
                freq.erase(to_fill);
            }
            i += 2;
        }
        return barcodes;
    }
};
