class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // assume m > n
        // brute: sort both, two pointer, mlogm + nlogn + n
        // sort smaller one, bin search, nlogn + mlogn
        // hashmap one: m + n, space n
        if (nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }
        unordered_map<int, bool> m;
        for(int i = 0; i < nums2.size(); i++) {
            m[nums2[i]] = true;
        }
        vector<int> intersec;
        for(int i = 0; i < nums1.size(); i++){
            if (m[nums1[i]]) {
                intersec.push_back(nums1[i]);
                m[nums1[i]] = false;
            }
        }
        return intersec;
    }
};
