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
        if (head == NULL || k == 1) {
            return head;
        }
        //counting, so dont need to reverse the last <k nodes
        int num = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            num++;
        }
        
        //leave a dummy pointer to the new head
        ListNode** constant_ptr_to_head = &head;
        //this dummy pointer would move
        ListNode** ptr_to_head = constant_ptr_to_head;
        
        ListNode* next = NULL;
        //also make sure all nodes exist
        while (num >= k) {
            cur = *ptr_to_head;
            next = cur->next;
            //careful start from 1
            for (int i = 1; i < k; i++) {
                cur->next = next->next;
                next->next = *ptr_to_head;
                *ptr_to_head = next;
                next = cur->next;
            }
            ptr_to_head = &(cur->next);
            num -= k;
        }
        return *constant_ptr_to_head;
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
