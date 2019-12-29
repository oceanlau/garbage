class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> freq;
        int len = S.length();
        for(const char s : S) {
            freq[s]++;
        }
        priority_queue<pair<int, char>> pq;
        for (const auto& p : freq) {
            if(p.second > (len+1)/2) {
                return "";
            }
            pq.push(make_pair(p.second, p.first));
        }
        string res;
        while(pq.size() != 0){
            pair<int, char> p1 = pq.top();
            pq.pop();
            res += p1.second;
            if(pq.size() != 0) {
                pair<int, char> p2 = pq.top();
                pq.pop();
                res += p2.second;
                if (--p2.first > 0) {
                    pq.push(p2);
                }
            }
            if (--p1.first > 0) {
                pq.push(p1);
            }
            
        }
        return res;
    }
};
