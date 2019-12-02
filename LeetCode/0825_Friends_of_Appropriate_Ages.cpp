class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // naive way is n^2
        // since age len << n. Could use bucket counting
        // for each A. find all B satisfying this cond:
        // 0.5A+7 < B <= A. A must be at least 15 to send friend request
        // use presum to get this from O(age len ^ 2) to O(age len)
        
        unordered_map<int, int> age_map;
        for (const int age : ages) {
            age_map[age]++;
        }
        //careful here
        vector<int> presum(121, 0);
        presum[0] = age_map[0];
        for (int i = 1; i < presum.size(); i++) {
            presum[i] = presum[i - 1] + age_map[i];
        }
        int res = 0;
        for (int a = 15; a <= 120; a ++) {
            int B = presum[a] - presum[0.5*a+7];
            //res += (B - age_map[A])*age_map[A] + age_map[A]*(age_map[A] - 1);
            res += (B - 1)*age_map[a];
        }
        return res;
    }
};
