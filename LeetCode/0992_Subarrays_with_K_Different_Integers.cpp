// 99% 100%
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // l r mark the window
        // cur_k
        // vector 'count' is the number of appeareance of each element
        // for each r, update count vector and cur_k
        //     update max_l to find the 'max', by decreasing count vec, find the last potential pos of l before cur_k become less than K
        //     when cur_k == K, res += max_l - l + 1
        //     when cur_k > K, l = max_l + 1, update count vec, cur_k --, max_l ++
        int res = 0;
        //1 <= A[i] <= A.length
        vector<int> count(A.size() + 1, 0);
        int l = 0;
        int r = 0;
        int max_l = 0;
        int cur_k = 0;
        int last_r = -1;
        while (r < A.size()) {
            if (r > last_r && count[A[r]]++ == 0) {
                cur_k ++;
            }
            last_r = r;
            while (count[A[max_l]] > 1) {
                count[A[max_l]]--;
                max_l ++;
            }
            if (cur_k == K) {
                res += max_l - l + 1;
            } else if (cur_k > K) {
                count[A[max_l]]--;
                l = max_l + 1;
                max_l ++;
                cur_k --;
                continue;
            }
            r++;
        }        
        return res;
    }
};

//Maybe ordered map would be much better
//Using sliding window and real map of last_pos, barely not tle 5% 40%
class Solution {
private:
    int _findMin(unordered_map<int, int>& last_pos){
        int min_pos = INT_MAX;
        for (auto it = last_pos.begin(); it != last_pos.end(); it++) {
            if (it->second < min_pos) {
                min_pos = it->second;
            }
        }
        return min_pos;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // A sliding window with 3 ptrs
        // l, r, max_l
        // max_l is the min in last_pos for each elem (array)
        // so num += max_l - l + 1 for each step of r
        // when cur_k > K, move l to the max_l+1
        int res = 0;
        //1 <= A[i] <= A.length, dont forget  + 1!! >= 1!!
        unordered_map<int, int> last_pos;
        int l = 0;
        int r = 0;
        int cur_k = 0;
        while (r < A.size()) {
            // remember to erase
            if (last_pos.find(A[r]) == last_pos.end()) {
                cur_k ++;
            }
            last_pos[A[r]] = r;
            if (cur_k == K) {
                res += _findMin(last_pos) - l + 1;
            } else if (cur_k > K) {
                //special case! Lots of things to consider here!
                int min_last_pos = _findMin(last_pos);
                l = min_last_pos + 1;
                //erase
                last_pos.erase(A[min_last_pos]);// or erase
                cur_k --;
                continue;
            }
            r++;
        }        
        return res;
    }
};

//Using sliding window with vector as map of last_pos, still O(n^2), still TLE
class Solution {
private:
    int _findMin(vector<int>& last_pos){
        return *min_element(last_pos.begin(), last_pos.end());
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // A sliding window with 3 ptrs
        // l, r, max_l
        // max_l is the min in last_pos for each elem (array)
        // so num += max_l - l + 1 for each step of r
        // when cur_k > K, move l to the max_l+1
        int res = 0;
        //1 <= A[i] <= A.length, dont forget  + 1!! >= 1!!
        vector<int> last_pos(A.size() + 1, A.size());
        int l = 0;
        int r = 0;
        int cur_k = 0;
        while (l < A.size() && r < A.size()) {
            if (last_pos[A[r]] == A.size()) {
                cur_k ++;
            }
            last_pos[A[r]] = r;
            if (cur_k == K) {
                res += _findMin(last_pos) - l + 1;
            } else if (cur_k > K) {
                //special case! Lots of things to consider here!
                int min_last_pos = _findMin(last_pos);
                l = min_last_pos + 1;
                last_pos[A[min_last_pos]] = A.size();
                cur_k --;
                continue;
            }
            r++;
        }        
        return res;
    }
};

// O(n^2) TLE
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            int cur_k = 0;
            //since 1 <= A[i] <= A.length
            vector<bool> exists(A.size(), false);
            for (int j = i; j < A.size(); j++) {
                if (!exists[A[j] - 1]) {
                    cur_k ++;
                }
                exists[A[j] - 1] = true;
                if (cur_k == K) {
                    res ++;
                } else if (cur_k > K) {
                    break;
                }
            }
        }
        return res;
    }
};
