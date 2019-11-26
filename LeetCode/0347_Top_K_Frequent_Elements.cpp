class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>> freq_val;
        for(auto item : freq) {
            freq_val.push(make_pair(item.second, item.first));
        }
        vector<int> res;
        while (k > 0 && freq_val.size() > 0) {
            res.push_back(freq_val.top().second);
            freq_val.pop();
            k --;
        }
        return res;
    }
};
