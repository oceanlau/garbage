class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> dec_st;
        for (int i = 0; i < 2*n; i ++) {
            int j = i % n;
            while (!dec_st.empty() && nums[dec_st.top()] < nums[j]) {
                if (res[dec_st.top()] == -1) {
                    res[dec_st.top()] = nums[j];
                }
                dec_st.pop();
            }
            dec_st.push(j);
        }
        return res;
    }
};
