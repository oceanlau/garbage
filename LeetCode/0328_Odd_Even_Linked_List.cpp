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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* oddnode = head;
        ListNode* evenhead = head->next;
        ListNode* evennode = head->next;
        while (evennode) {
            oddnode->next = evennode->next;
            if (oddnode->next) {
                oddnode = oddnode->next;
                evennode->next = oddnode->next;
            } else {
                evennode->next = NULL;
            }
            evennode = evennode->next;
        }
        oddnode->next = evenhead;
        return head;
    }
};
