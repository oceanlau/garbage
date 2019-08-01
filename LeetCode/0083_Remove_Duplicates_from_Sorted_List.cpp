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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* inspect_node = head;
        ListNode** ptr_rewrite_node = &head;
        int last = inspect_node->val;
        (*ptr_rewrite_node)->val = inspect_node->val;
        ptr_rewrite_node = &((*ptr_rewrite_node)->next);
        
        while (inspect_node != NULL) {
            if (last != inspect_node->val) {
                last = inspect_node->val;
                (*ptr_rewrite_node)->val = inspect_node->val;
                ptr_rewrite_node = &((*ptr_rewrite_node)->next);
            }
            inspect_node = inspect_node->next;
        }
        *ptr_rewrite_node = NULL;
        return head;
    }
};
