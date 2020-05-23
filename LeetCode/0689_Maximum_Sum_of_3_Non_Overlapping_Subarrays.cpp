class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // suppose the mid subarray starting location is i
        // left_maxsum_idx[] are starting location of the max sum k len subarray before i
        // right_maxsum_idx[] are starting location of the max sum k len subarray after i+k
        // we move i from k to n - 2k, 3 times
        // first 2 times calculate the left and right idx
        // last one find the answer
        // to make this O(n), we use presum
        int n = nums.size();
        vector<int> presum (n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        
        //vector<int> left_maxsum_idx (n - 3 * k + 1, 0);
        //vector<int> right_maxsum_idx (n - 3 * k + 1, 0);
        vector<int> left_maxsum_idx (n, 0);
        vector<int> right_maxsum_idx (n, 0);
        
        int l_maxsum = -1;
        for (int i = k; i <= n - 2 * k; i++) {
            int l_new_start = i - k;
            int l_new_end = i - 1;
            // presum starts from 1, other idxes start from 0
            int l_new_sum = presum[l_new_end + 1] - presum[l_new_start];
            if (l_new_sum > l_maxsum) {
                l_maxsum = l_new_sum;
                left_maxsum_idx[l_new_start] = l_new_start;
            } else {
                //reuse last max result so far
                left_maxsum_idx[l_new_start] = left_maxsum_idx[l_new_start - 1];
            }
        }
        
        int r_maxsum = -1;
        for (int i = n - 2 * k; i >= k; i--) {
            int r_new_start = i + k;
            int r_new_end = i + 2 * k - 1;
            int r_new_sum = presum[r_new_end + 1] - presum[r_new_start];
            // super careful, the question asks for smallest lexi
            if (r_new_sum >= r_maxsum) {
                r_maxsum = r_new_sum;
                right_maxsum_idx[r_new_start] = r_new_start;
            } else {
                //reuse last max result so far
                right_maxsum_idx[r_new_start] = right_maxsum_idx[r_new_start + 1];
            }
        }
        
        int maxsum = -1;
        vector<int> ans;
        for (int i = k; i <= n - 2 * k; i++) {
            int l_start = left_maxsum_idx[i - k];
            int l_sum = presum[l_start + k] - presum[l_start];
            int mid_sum = presum[i + k] - presum[i];
            int r_start = right_maxsum_idx[i + k];
            int r_sum = presum[r_start + k] - presum[r_start];
            if (l_sum + mid_sum + r_sum > maxsum) {
                maxsum = l_sum + mid_sum + r_sum;
                ans = {l_start, i, r_start};
            }
        }
        
        return ans;
    }
};
