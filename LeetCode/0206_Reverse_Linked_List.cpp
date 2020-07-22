/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        while (head) {
            ListNode* nex = head->next;
            head->next = last;
            last = head;
            if (nex) {
                head = nex;
            } else {
                return head;
            }
        }
        return head;
    }
};
