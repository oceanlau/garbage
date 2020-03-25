/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> g(G.begin(), G.end());
        int ans = 0;
        bool same_group = false;
        while (head != NULL) {
            if (g.count(head->val)) {
                if (!same_group) {
                    ans ++;
                    same_group = true;
                }
            } else {
                same_group = false;
            }
            head = head->next;
        }
        return ans;
    }
};
