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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        vector<ListNode*> node_ptr_vec {head};
        ListNode* node = head;
        while (node->next != NULL) {
            node = node->next;
            node_ptr_vec.push_back(node);
        }
        int vec_size = node_ptr_vec.size();
        if (k % vec_size == 0) {
            return head;
        }
        int new_head_pos = vec_size - k % vec_size;
        if (new_head_pos - 1 >= 0) {
            node_ptr_vec[new_head_pos - 1]->next = NULL;
        }
        if (vec_size > 1) {
            node_ptr_vec[vec_size - 1]->next = head;
        }
        return node_ptr_vec[new_head_pos];
    }
};
