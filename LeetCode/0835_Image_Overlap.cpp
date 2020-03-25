class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.size() == 0) {
            return 0;
        }
        unordered_map<string, int> trans_bucket;
        vector<pair<int, int>> A1;
        vector<pair<int, int>> B1;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j] == 1) {
                    A1.emplace_back(i, j);
                }
            }
        }
        for (int i = 0; i < B.size(); i++) {
            for (int j = 0; j < B[0].size(); j++) {
                if (B[i][j] == 1) {
                    B1.emplace_back(i, j);
                }
            }
        }
        for (int i = 0; i < A1.size(); i++) {
            for (int j = 0; j < B1.size(); j++) {
                trans_bucket[to_string(A1[i].first - B1[j].first) + "_" + to_string(A1[i].second - B1[j].second)] ++;
            }
        }
        int max_num = 0;
        for (const auto& t : trans_bucket) {
            max_num = max(max_num, t.second);
        }
        return max_num;
    }
};
