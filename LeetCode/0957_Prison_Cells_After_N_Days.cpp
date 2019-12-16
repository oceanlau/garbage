class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> first(cells.size(), 0);
        for (int i = 1; i < cells.size() - 1; i++) {
            first[i] = cells[i - 1] == cells[i + 1];
        }
        //注意！
        N --;
        cells = first;
        //注意！
        int cycle = 1;
        while (N > 0) {
            vector<int> tmp = cells;
            for (int i = 1; i < cells.size() - 1; i++) {
                tmp[i] = cells[i - 1] == cells[i + 1];
            }
            //注意！
            N --;
            if (tmp == first) {
                N %= cycle;
            }
            cells = tmp;
            //注意！
            cycle ++;
        }
        return cells;
    }
};
