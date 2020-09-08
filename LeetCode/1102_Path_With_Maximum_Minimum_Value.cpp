class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int R = A.size();
        int C = A[0].size();
        vector<vector<int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<vector<int>> next_steps;
        int max_min_score = A[0][0];
        next_steps.push({A[0][0], 0, 0});
        A[0][0] = -1;
        while (true) {
            vector<int> cur = next_steps.top();
            next_steps.pop();
            max_min_score = min(cur[0], max_min_score);
            if (cur[1] == R - 1 && cur[2] == C - 1) {
                break;
            }
            for (const auto& d : dirs) {
                int r = cur[1] + d[0];
                int c = cur[2] + d[1];
                if (r >= 0 && r < R && c >= 0 && c < C && A[r][c] >= 0) {
                    next_steps.push({A[r][c], r, c});
                    // set here to avoid dupe
                    A[r][c] = -1;
                }
            }
        }
        return max_min_score;
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int h = A.size();
        int w = A[0].size();
        vector<vector<int>> dirs {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(A[0][0], 0, 0);
        int maxScore = A[0][0];
        A[0][0] = -1;
        while (!pq.empty()) {
            tuple<int, int, int> next_one = pq.top();
            pq.pop();
            maxScore = min(maxScore, get<0>(next_one));
            if (get<1>(next_one) == h - 1 && get<2>(next_one) == w - 1) {
                return maxScore;
            }
            for (const auto& d : dirs) {
                int i = get<1>(next_one) + d[0];
                int j = get<2>(next_one) + d[1];
                if (i >= 0 && i < h && j >= 0 && j < w && A[i][j] != -1) {
                    pq.emplace(A[i][j], i, j);
                    A[i][j] = -1;
                }
            }
        }
        return maxScore;
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        vector<pair<int, int>> dirs {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        priority_queue<tuple<int, int, int>> pq; // number, i, j
        pq.emplace(A[0][0], 0, 0);
        int h = A.size();
        int w = A[0].size();
        int max_val = A[0][0];
        A[0][0] = -1; // visited
        while(!pq.empty()) {
            auto [val, i, j] = pq.top();
            pq.pop();
            max_val = min(val, max_val);
            if (i == h - 1 && j == w - 1) {
                return max_val;
            }
            for (const pair<int, int>& dir : dirs) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && A[ni][nj] != -1) {
                    pq.emplace(A[ni][nj], ni, nj);
                    A[ni][nj] = -1;
                }
            }
        }
        return max_val;
    }
};
