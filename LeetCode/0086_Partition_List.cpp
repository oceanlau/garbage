// straight forward thinking, complicated code.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode** ptr_inspect_node = &head;
        ListNode** ptr_insert_node = NULL;
        ListNode* new_head = head;
        //tmp:
        ListNode* insert_node_next = NULL;
        while (ptr_inspect_node != NULL && *ptr_inspect_node != NULL) {
            if ((*ptr_inspect_node)->val < x) {
                if (ptr_insert_node == NULL) {
                    if (*ptr_inspect_node == head) {
                        ptr_insert_node = &head;
                    } else {
                        new_head = new ListNode(**ptr_inspect_node);
                        ptr_insert_node = &new_head;
                        (*ptr_insert_node)->next = head;
                        *ptr_inspect_node = (*ptr_inspect_node)->next;
                        continue;
                    }
                } else {
                    if (*ptr_inspect_node == (*ptr_insert_node)->next) {
                        ptr_insert_node = &((*ptr_insert_node)->next);
                    } else {
                        insert_node_next = (*ptr_insert_node)->next;
                        (*ptr_insert_node)->next = new ListNode(**ptr_inspect_node);
                        ptr_insert_node = &((*ptr_insert_node)->next);
                        (*ptr_insert_node)->next = insert_node_next;
                        *ptr_inspect_node = (*ptr_inspect_node)->next;
                        continue;
                    }
                }
            }
            
            if ((*ptr_inspect_node)->next != NULL) {
                ptr_inspect_node = &((*ptr_inspect_node)->next);
            } else {
                ptr_inspect_node = NULL;
            }
        }
        return new_head;
    }
};
