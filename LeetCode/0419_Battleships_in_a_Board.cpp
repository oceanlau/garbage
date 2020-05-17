class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int h = board.size();
        if (h == 0) {
            return 0;
        }
        int w = board[0].size();
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'X' && (i == h-1 || board[i+1][j] != 'X') && (j == w-1 || board[i][j+1] != 'X')) {
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};
