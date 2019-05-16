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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // error without NULL
        ListNode* h = NULL;
        ListNode* loop = NULL;
        while(true) {
            if (!l1 && !l2) {
                break;
            }
            // error without !!l2
            if (!l1 || (!!l2 && l1->val >= l2->val)) {
                if(!h) {
                    loop = l2;
                    h = loop;
                } else {
                    loop->next = l2;
                    loop = loop->next;
                }
                l2 = l2->next;
            } else {
                if(!h) {
                    loop = l1;
                    h = loop;
                } else {
                    loop->next = l1;
                    loop = loop->next;
                }
                l1 = l1->next;
            }
            
        }
        return h;
    }
};
