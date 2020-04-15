class Solution {
private:
    int _islands = 0;
    vector<int> _parent;
    void _u(int i, int j) {
        int pi = _f(i);
        int pj = _f(j);
        if (pi != pj) {
            _parent[pj] = pi;
            _islands --;
        }
    }
    int _f(int i) {
        while(_parent[i] != i) {
            i = _parent[i];
        }
        return i;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        _islands = stones.size();
        unordered_map<int, int> share_y;
        unordered_map<int, int> share_x;
        _parent = vector<int> (stones.size(), -1);
        for (int i = 0; i < stones.size(); i++) {
            _parent[i] = i;
            if (!share_y.count(stones[i][0])) {
                share_y[stones[i][0]] = i;
            } else {
                _u(share_y[stones[i][0]], i);
            }
            if (!share_x.count(stones[i][1])) {
                share_x[stones[i][1]] = i;
            } else {
                _u(share_x[stones[i][1]], i);
            }
        }
        return stones.size() - _islands;
    }
};
