class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* new_head = head->next;
        ListNode* l = NULL;
        ListNode* r = NULL;
        ListNode* last = head;
        while (true) {
            if (head == NULL || head->next == NULL) {
                last->next = head;
                break;
            }
            l = head;
            r = head->next;
            head = r->next;
            r->next = l;
            last->next = r;
            last = l;
        }
        return new_head;
    }
};
