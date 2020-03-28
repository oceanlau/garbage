class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> num_seq_end_at;
        
        for (const int n : nums) {
            freq[n] ++;
        }
        
        for (const int n : nums) {
            if (freq[n] == 0) {
                continue;
            }
            if (num_seq_end_at[n-1] > 0) {
                num_seq_end_at[n-1] --;
                num_seq_end_at[n] ++;
            } else if (freq[n+1] > 0 && freq[n+2] > 0){
                freq[n+1] --;
                freq[n+2] --;
                num_seq_end_at[n+2] ++;
            } else {
                return false;
            }
            freq[n] --;
        }
        return true;
    }
};
