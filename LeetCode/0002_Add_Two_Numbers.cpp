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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* result_current;
        ListNode* new_node;
        int is_overflowed = false;
        int val1;
        int val2;

        while (l1 != NULL || l2 != NULL || is_overflowed) {
            if (l1 == NULL) {
                val1 = 0;
            } else {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2 == NULL) {
                val2 = 0;
            } else {
                val2 = l2->val;
                l2 = l2->next;
            }
            int sum = val1 + val2;

            if (is_overflowed) {
                is_overflowed = false;
                sum += 1;
            }

            if (sum > 9) {
                is_overflowed = true;
                new_node = new ListNode(sum - 10);
            } else {
                new_node = new ListNode(sum);
            }

            if (result == NULL) {
                result = new_node;
                result_current = result;
            } else {
                result_current->next = new_node;
                result_current = new_node;
            }
        }

        return result;
    }
};