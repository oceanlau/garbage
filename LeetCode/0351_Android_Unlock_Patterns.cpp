class Solution {
private:
    vector<vector<int>> middleman;
    int _bt(int last, int remaining, vector<bool>& visited, vector<vector<int>>& middleman) {
        if (remaining == 0) {
            return 1;
        }
        visited[last] = true;
        int ans = 0;
        for (int i = 1; i <= 9; i++) {
            if (!visited[i] && (middleman[last][i] == 0 || visited[middleman[last][i]])) {
                visited[i] = true;
                ans += _bt(i, remaining - 1, visited, middleman);
                visited[i] = false;
            }
        }
        visited[last] = false;
        return ans;
    }
public:
    int numberOfPatterns(int m, int n) {
        middleman = vector<vector<int>> (10, vector<int> (10, 0));
        middleman[1][3] = middleman[3][1] = 2;
        middleman[3][9] = middleman[9][3] = 6;
        middleman[7][9] = middleman[9][7] = 8;
        middleman[1][7] = middleman[7][1] = 4;
        middleman[1][9] = middleman[9][1] = 5;
        middleman[2][8] = middleman[8][2] = 5;
        middleman[3][7] = middleman[7][3] = 5;
        middleman[4][6] = middleman[6][4] = 5;
        int ans = 0;
        vector<bool> visited(10, false);
        while (m <= n) {
            ans += 4 * _bt(1, m - 1, visited, middleman);
            ans += 4 * _bt(2, m - 1, visited, middleman);
            ans += _bt(5, m - 1, visited, middleman);
            m++;
        }
        return ans;
    }
};
