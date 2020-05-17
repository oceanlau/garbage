class Solution {
private:
    int num = 0;
    void connect(int m, int n) {
        int rm = root(m);
        if (rm == -1) {
            rm = m;
            parents[m] = m;
        }
        int rn = root(n);
        if (rn == -1) {
            rn = n;
            parents[n] = n;
        }
        if (rm != rn) {
            parents[rn] = rm;
            num --;
        }
    }
    int root(int m) {
        while (parents[m] != m && parents[m] != -1) {
            m = parents[m];
        }
        return parents[m];
    }
    vector<int> parents;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        num = n;
        parents.resize(num, -1);
        /*
        for (int i = 0; i < num; i++) {
            parents[i] = i;
        }*/
        for (const vector<int>& e : edges) {
            connect(e[0], e[1]);
        }
        return num;
    }
};
