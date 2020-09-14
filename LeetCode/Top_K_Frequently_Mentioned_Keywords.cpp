#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

vector<string> topk(int k, vector<string>& kws, vector<string>& reviews) {
    vector<string> result;
    unordered_map<string, int> freqs;
    for (const string& kw : kws) {
        freqs[kw] = 0;
    }
    for (const string& review : reviews) {
        string last;
        unordered_set<string> seen;
        for (int i = 0; i <= review.length(); i ++) {
            if (i < review.length() && isalpha(review[i])) {
                last += tolower(review[i]);
            } else {
                if (last.length() > 0 && !seen.count(last) && freqs.count(last)) {
                    freqs[last] ++;
                    seen.insert(last);
                }
                last = "";
            }
        }
    }
    auto comp = [](const pair<string, int>& l, const pair<string, int>& r){
        if (l.second == r.second) {
            return l.first < r.first;
        }
        return l.second > r.second;
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> top(comp);
    for (const auto& p : freqs) {
        top.push(p);
        if (top.size() > k) {
            top.pop();
        }
    }
    while (top.size() != 0) {
        result.push_back(top.top().first);
        top.pop();
    }
    reverse(result.begin(), result.end());
    return result;
};

int main() {
    vector<string> k1 {"anacell", "cetracular", "betacellular"};
    vector<string> r1 {"Anacell provides the best services in the city",
  "betacellular has awesome services",
  "Best services provided by anacell, everyone should use anacell"};
    vector<string> result = topk(2, k1, r1);
    for (const string& r : result) {
        cout << r << ", ";
    }
    cout << endl;

    vector<string> k2 {"anacell", "betacellular", "cetracular", "deltacellular", "eurocell"};
    vector<string> r2 {"I love anacell Best services; Best services provided by anacell",
  "betacellular has great services",
  "deltacellular provides much better services than betacellular",
  "cetracular is worse than anacell",
  "Betacellular is better than deltacellular."};
    result = topk(2, k2, r2);
     for (const string& r : result) {
         cout << r << ", ";
     }
    return 0;
};
