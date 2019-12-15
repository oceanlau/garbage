class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(n) build map size f(could be as large as n)
        // heap or quick select O(flogk) or O(nlogk)
        // put in buckets of eles, find top buckets, O(k)
        if (k == 0 || k > nums.size()) {
            return {};
        }
        unordered_map<int, int> freq;
        for (const int num : nums) {
            freq[num] ++;
        }
        int n = nums.size();
        //O(n) space, more than heap or quick select required, but faster
        vector<vector<int>> bucket(n, vector<int> {});
        for (const auto& kv : freq) {
            bucket[kv.second - 1].push_back(kv.first);
        }
        vector<int> res;
        for (int i = n - 1; i >= 0; i--) {
            //if (bucket[i].size() > 0) {
                //k --;
                //res.insert(res.end(), bucket[i].begin(), bucket[i].end());//more overflow k
                for (const int num : bucket[i]) {
                    res.push_back(num);
                    if (res.size() == k) {
                        return res;
                    }
                }
            //}
        }
        return res;
    }
};

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
