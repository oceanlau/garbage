class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](const vector<int>& lhs, const vector<int>& rhs){
            if (lhs[0] == rhs[0]) {
                return lhs[1] < rhs[1];
            }
            return lhs[0] > rhs[0];
        };
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> q;
        for (const vector<int>& p : people) {
            q.insert(q.begin() + p[1], p);
        }
        return q;
    }
};
