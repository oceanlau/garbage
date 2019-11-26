class Solution {
private:
    vector<int> s;
    int _bin_search(int target) {
        int l = 0;
        int r = s.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (s[mid] >= target && (mid == 0 || s[mid - 1] < target)) {
                return mid;
            }
            if (s[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (s[l] >= target && (l == 0 || s[l - 1] < target)) {
            return l;
        }
        return r;
    }
public:
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++) {
            if (i == 0) {
                s.push_back(w[i]);
            } else {
                s.push_back(s[i - 1] + w[i]);
            }
        }
    }
    
    int pickIndex() {
        return _bin_search(rand() % s.back() + 1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
