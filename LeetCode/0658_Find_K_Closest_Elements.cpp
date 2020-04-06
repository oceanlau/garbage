class Solution {
private:
    pair<int, int> _locate(vector<int>& arr, int& x) {
        int i = 0;
        int j = arr.size() - 1;
        while (j - i > 1) {
            int mid = i + (j - i) / 2;
            if (arr[mid] == x) {
                return make_pair(mid, mid);
            } else if (arr[mid] > x) {
                j = mid;
            } else if (arr[mid] < x) {
                i = mid;
            }
        }
        if (arr[i] >= x) {
            return make_pair(i, i);
        } else if (arr[j] <= x) {
            return make_pair(j, j);
        } else {
            return make_pair(i, j);
        }
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == 0) {
            return {};
        }
        pair<int, int> closest_idxes = _locate(arr, x);
        int i = closest_idxes.first;
        int j = closest_idxes.second;
        int l = -1;
        int r = -1;
        if (abs(arr[i] - x) <= abs(arr[j] - x)) {
            l = i;
            r = i;
        } else {
            l = j;
            r = j;
        }
        k --;
        while (k > 0) {
            if (l == 0) {
                r++;
            } else if (r == arr.size() - 1) {
                l--;
            } else {
                if (abs(arr[l-1] - x) <= abs(arr[r+1] - x)) {
                    l --;
                } else {
                    r ++;
                }
            }
            k --;
        }
        return vector<int> (arr.begin() + l, arr.begin() + r + 1);
    }
};


// Dont push & insert. Do it in the end with the indexes. 74% 66%
class Solution {
private:
    int _binsearch(vector<int>& arr, int i, int j, int target) {
        while (i + 1 < j) {
            int m = i + (j-i)/2;
            if (arr[m] == target) {
                return m;
            } else if (arr[m] > target) {
                j = m;
            } else {
                i = m;
            }
        }
        // Dont forget the equal sign!! Its possible to skip the while part
        if (arr[i] >= target || target - arr[i] <= arr[j] - target) {
            return i;
        } else {
            return j;
        }
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() == 0) {
            return vector<int> {};
        }
        // binary search to find the closest idx
        int idx = _binsearch(arr, 0, arr.size() - 1, x);
        // start from idx, compare idx, then set i, j = idx -+ 1
        int i = idx - 1;
        int j = idx + 1;
        // if j-idx < idx-i, push j, j++. else push i, i-- until j-i == k or k-1
        // k always smaller than length of the array. One less edge to worry about.
        // i j idx not included!
        while (j - i <= k) {
            if (i < 0) {
                j ++;
            } else if (j == arr.size() || x - arr[i] <= arr[j] - x) {
                i --;
            } else {
                j ++;
            }
        }
        return vector<int> (arr.begin() + i + 1, arr.begin() + j);
    }
};

// O(n+logn) 9% 16%
class Solution {
private:
    int _binsearch(vector<int>& arr, int i, int j, int target) {
        while (i + 1 < j) {
            int m = i + (j-i)/2;
            if (arr[m] == target) {
                return m;
            } else if (arr[m] > target) {
                j = m;
            } else {
                i = m;
            }
        }
        // Dont forget the equal sign!! Its possible to skip the while part
        if (arr[i] >= target || target - arr[i] <= arr[j] - target) {
            return i;
        } else {
            return j;
        }
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if (arr.size() == 0) {
            return res;
        }
        // binary search to find the closest idx
        int idx = _binsearch(arr, 0, arr.size() - 1, x);
        // start from idx, compare idx, then set i, j = idx -+ 1
        int i = idx - 1;
        int j = idx + 1;
        res.push_back(arr[idx]);
        // if j-idx < idx-i, push j, j++. else push i, i-- until j-i == k or k-1
        // k always smaller than length of the array. One less edge to worry about.
        while (j - i <= k) {
            if (i < 0) {
                res.push_back(arr[j]);
                j ++;
            } else if (j == arr.size()) {
                res.insert(res.begin(), arr[i]);
                i --;
            } else if (x - arr[i] <= arr[j] - x){
                res.insert(res.begin(), arr[i]);
                i--;
            } else {
                res.push_back(arr[j]);
                j++;
            }
        }
        return res;
    }
};
