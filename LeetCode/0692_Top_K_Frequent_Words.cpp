class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // map of word - freq O(n)
        // naive sort O(nlogn)
        // min heap of pair {word,freq}, O(nlogk)
        // pair {word,freq}, quick select and sort O(logn + klogk) ?
        
        // min heap
        auto cmp = [](const pair<string, int>& l, const pair<string, int>& r){
            if (l.second == r.second) {
                return l.first < r.first;
            } else {
                return l.second > r.second;
            }
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> top(cmp);
        unordered_map<string, int> freqs;
        for (const string& word : words) {
            freqs[word]++;
        }
        for (const pair<string, int>& kv : freqs) {
            // push first!
            top.push(kv);
            if (top.size() > k) {
                top.pop();
            }
        }
        vector<string> res;
        while (top.size() != 0) {
            res.push_back(top.top().first);
            top.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
