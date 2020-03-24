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
    ListNode* plusOne(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* lastNon9 = NULL;
        ListNode* node = head;
        while (node) {
            if (node->val != 9) {
                lastNon9 = node;
            }
            node = node->next;
        }
        /*
        if (node->val != 9) {
            node->val++;
            return head;
        }*/
        if (lastNon9) {
            lastNon9->val++;
        } else {
            lastNon9 = new ListNode(1);
            lastNon9->next = head;
            head = lastNon9;
        }
        node = lastNon9->next;
        while (node) {
            node->val = 0;
            node = node->next;
        }
        return head;
    }
};
