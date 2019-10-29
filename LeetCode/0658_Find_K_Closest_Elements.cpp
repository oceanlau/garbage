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
