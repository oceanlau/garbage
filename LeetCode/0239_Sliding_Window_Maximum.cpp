class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dec_indexes;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // pop_backs and push_back
            while (!dec_indexes.empty() && nums[dec_indexes.back()] <= nums[i]) {// <= cuz we only need one
                dec_indexes.pop_back();
            }
            dec_indexes.push_back(i);
            if (i >= k) {
                // pop_front
                if (dec_indexes.front() == i - k) {
                    dec_indexes.pop_front();
                }
            }
            if (i >= k - 1) {
                // return front
                res.push_back(nums[dec_indexes.front()]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // try to be O(n) total. 
        // delete the first element, try to be O(1)
        // map of val -> iterator in set (delete in set, delete map element)
        // add the last element
        // add in set, then map
        // calculate max, rb tree: heap(can't be delete at idx) or set. set of vals
        //
        // but there may be dupes, so use set of pair<val, count>
        // bad idea to update set!!
        
        // new thinking: ordered map of val -> counter
        map<int, int> counter;
        //initial k
        if (nums.size() == 0) {
            return {};
        }
        if (k > nums.size()) {
            k = nums.size();
        }
        for (int i = 0; i < k; i++) {
            counter[nums[i]] ++;
        }
        vector<int> res {counter.rbegin()->first};
        for (int i = k; i < nums.size(); i++) {
            counter[nums[i]] ++;
            if (--counter[nums[i - k]] == 0) {
                counter.erase(nums[i - k]);
            }
            res.push_back(counter.rbegin()->first);
        }
        return res;
    }
};
