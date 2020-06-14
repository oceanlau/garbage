class Solution {
private:
    vector<int> parents;
    int find(int idx) {
        while(parents[idx] != idx) {
            idx = parents[idx];
        }
        return idx;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int cnt = 0;
        vector<int> res;
        parents.resize(m*n, -1);
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (const vector<int>& p : positions) {
            int i = p[0];
            int j = p[1];
            int idx = i * n + j;
            if (parents[idx] != -1) {
                res.push_back(cnt);
                continue;
            }
            parents[idx] = idx;
            cnt ++;
            for (const vector<int>& d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && parents[ni * n + nj] != -1) {
                    int myroot = find(idx);
                    int hisroot = find(ni * n + nj);
                    if (myroot != hisroot) {
                        cnt --;
                        parents[myroot] = hisroot;
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};
