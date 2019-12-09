class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 1.one pass, min heap, nlogn
        // 2.two pass, bucket of elements, n+n/2
        
        // 3.sort, its in the middle ologn
        // 4.Boyer-Moore Voting Alg
        // 当count为0，就当前元素为答案，遇到相同元素+1，不同-1，最后count肯定>=0，最后设的元素就是答案
        int count = 0;
        int candidate = 0;
        for(const int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count ++;
            } else {
                count --;
            }
        }
        return candidate;
    }
};
