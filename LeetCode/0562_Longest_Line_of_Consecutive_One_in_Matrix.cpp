class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int h = M.size();
        if (h == 0) {
            return 0;
        }
        int w = M[0].size();
        int longest = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (M[i][j] == 1) {
                    // starting at up left
                    if (!(i > 0 && j > 0 && M[i-1][j-1] == 1)) {
                        int ni = i + 1;
                        int nj = j + 1;
                        int len = 1;
                        while (ni < h && nj < w) {
                            if (M[ni][nj] == 1) {
                                len ++;
                            } else {
                                break;
                            }
                            ni ++;
                            nj ++;
                        }
                        longest = max(longest, len);
                    }
                    // starting at up
                    if (!(i > 0 && M[i-1][j] == 1)) {
                        int ni = i + 1;
                        int len = 1;
                        while (ni < h) {
                            if (M[ni][j] == 1) {
                                len ++;
                            } else {
                                break;
                            }
                            ni ++;
                        }
                        longest = max(longest, len);
                    }
                    // starting at up right
                    if (!(i > 0 && j < w - 1 && M[i-1][j+1] == 1)) {
                        int ni = i + 1;
                        int nj = j - 1;
                        int len = 1;
                        while (ni < h && nj >= 0) {
                            if (M[ni][nj] == 1) {
                                len ++;
                            } else {
                                break;
                            }
                            ni ++;
                            nj --;
                        }
                        longest = max(longest, len);
                    }
                    // starting at left
                    if (!(j > 0 && M[i][j-1] == 1)) {
                        int nj = j + 1;
                        int len = 1;
                        while (nj < w) {
                            if (M[i][nj] == 1) {
                                len ++;
                            } else {
                                break;
                            }
                            nj ++;
                        }
                        longest = max(longest, len);
                    }
                }
            }
        }
        return longest;
    }
};
