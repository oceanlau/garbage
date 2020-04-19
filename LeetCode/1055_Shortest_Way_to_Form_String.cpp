class Solution {
private:
    int first_idx_gt(vector<int>& idxs, int i) {
        int l = 0;
        int r = idxs.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (idxs[mid] > i) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (idxs[l] > i) {
            return idxs[l];
        } else if (idxs[r] > i) {
            return idxs[r];
        }
        return -1;
    }
public:
    int shortestWay(string source, string target) {
        if (target.length() == 0) {
            return 0;
        }
        vector<vector<int>> char_src_idxs(26, vector<int>{});
        int i = 0;
        for (; i < source.length(); i++) {
            char_src_idxs[source[i] - 'a'].push_back(i);
        }
        int ans = 1;
        i = -1;
        for (int j = 0; j < target.length();) {
            if (char_src_idxs[target[j] - 'a'].empty()) {
                return -1;
            }
            i = first_idx_gt(char_src_idxs[target[j] - 'a'], i);
            if (i == -1) {
                ans ++;
            } else {
                j++;
            }
        }
        return ans;
    }
};
