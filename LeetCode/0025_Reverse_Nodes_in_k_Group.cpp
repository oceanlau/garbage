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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) {
            return head;
        }
        ListNode** pp = &head;
        ListNode* end = head;
        while (end != NULL) {
            end = reverseGroup(pp, k);
        }
        return head;
    }
    
    ListNode* reverseGroup(ListNode** & pp, int k) {
        int c = 1;
        ListNode* end = *pp;
        while (k > 1 && end->next != NULL) {
            ListNode* tail = end->next;
            end->next = tail->next;
            tail->next = *pp;
            *pp = tail;
            k --;
            c ++;
        }
        
        if (k > 1) {
            return reverseGroup(pp, c);
        }
        
        pp = &(end->next);
        return end->next;
    }
    
};
