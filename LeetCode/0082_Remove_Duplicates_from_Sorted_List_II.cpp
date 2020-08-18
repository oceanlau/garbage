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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* last = dummy;
        last->next = head;
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                while (cur->next && cur->val == cur->next->val) {
                    cur->next = cur->next->next;
                }
                last->next = cur->next;
            } else {
                last = last->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};

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
        ListNode* new_head = NULL;
        ListNode* new_node = NULL;
        ListNode* inspect_node = head;
        while (inspect_node != NULL) {
            if (inspect_node->next == NULL || inspect_node->val != inspect_node->next->val) {
                if (new_head == NULL) {
                    new_head = inspect_node;
                    new_node = new_head;
                } else {
                    new_node->next->val = inspect_node->val;
                    new_node = new_node->next;
                }
            } else {
                while (inspect_node->next != NULL && inspect_node->val == inspect_node->next->val) {
                    inspect_node = inspect_node->next;
                }
            }
            inspect_node = inspect_node->next;
        }
        if (new_node != NULL) {
            new_node->next = NULL;
        }
        return new_head;
    }
};
