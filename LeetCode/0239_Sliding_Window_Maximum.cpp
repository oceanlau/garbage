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
