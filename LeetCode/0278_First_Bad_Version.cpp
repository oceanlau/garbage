// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
private:
    int _find(int i, int j) {
        if (i >= j) {
            if (isBadVersion(i)) {
                return i;
            } else {
                return i+1;
            }
        }
        int mid = i + (j-i)/2;
        if (isBadVersion(mid)) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
        return _find(i, j);
    }
public:
    int firstBadVersion(int n) {
        return _find(1, n);
    }
};
