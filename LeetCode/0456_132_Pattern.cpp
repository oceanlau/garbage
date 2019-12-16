class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //brute pick 3 O(n^3)
        //record min so far on each loc. For every num, compare with all prev locs O(n^2)
        //mono stack: two subproblem
        // 1. find min a_i, by a sweep from left to right to find min so far on each loc
        // 2. find a_j > a_k (and a_k > a_i) by building a dec mono stack from right
        
        // even better! only a dec stack from right!
        // a_k is the last one poped
        // a_j is implicitly the one that poped a_k out, this enforce j < k and a_j > a_k
        // if a new num < a_k, we've found it!
        //only reversed dir dec stack has the pattern for our answer!
        
        stack<int> dec_stack;
        int a_k = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < a_k) {
                return true;
            }
            while (dec_stack.size() > 0 && nums[i] > dec_stack.top()) {
                a_k = dec_stack.top();
                dec_stack.pop();
            }
            dec_stack.push(nums[i]);
        }
        return false;
        
        
        // mono inc stack dont work [3 5 0 3 4], 5 was discarded by 0 too early
        /*
        stack<int> mono_inc_stack;
        for (const int num : nums) {
            int size1 = mono_inc_stack.size();
            while (mono_inc_stack.size() > 0 && num < mono_inc_stack.top()) {
                mono_inc_stack.pop();
            }
            int size2 = mono_inc_stack.size();
            if (size2 > 0 && size1 > size2) {
                return true;
            }
            mono_inc_stack.push(num);
        }
        return false;
        */
    }
};
