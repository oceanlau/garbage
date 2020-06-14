class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> dec_st;
        unordered_map<int, int> next_g_m;
        for (const int n : nums1) {
            next_g_m[n] = -1;
        }
        for (const int n : nums2) {
            while (!dec_st.empty() && dec_st.top() < n) {
                if (next_g_m.count(dec_st.top()) && next_g_m[dec_st.top()] == -1) {
                    next_g_m[dec_st.top()] = n;
                }
                dec_st.pop();
            }
            dec_st.push(n);
        }
        vector<int> res;
        for (const int n : nums1) {
            res.push_back(next_g_m[n]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 对第二个数组反向设置monotonous decreasing stack
        // 每个元素都pop stack直到找到比自己大的元素，设map[自己] = 比自己大的。然后把自己push进去
        // 最后读第一个数组
        unordered_map<int, int> rbigger;
        stack<int> bigger;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (bigger.size() != 0 && nums2[i] >= bigger.top()){
                bigger.pop();
            }
            if (bigger.size() != 0) {
                rbigger[nums2[i]] = bigger.top();
            } else {
                rbigger[nums2[i]] = -1;
            }
            bigger.push(nums2[i]);
        }
        for (int& num : nums1) {
            num = rbigger[num];
        }
        return nums1;
    }
};
