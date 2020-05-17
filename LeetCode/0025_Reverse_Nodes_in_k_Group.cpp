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
private:
    void reverseGroup(ListNode* node, int& k, ListNode*& seg_head, ListNode*& next_seg_head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (node && k > 0) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
            k --;
        }
        seg_head = prev;
        next_seg_head = node;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        head = NULL;
        ListNode* last_seg_end = NULL;
        ListNode* seg_head = NULL;
        ListNode* next_seg_head = NULL;
        do {
            int _k = k;
            reverseGroup(node, _k, seg_head, next_seg_head);
            if (_k == 0) {
                if (!head) {
                    head = seg_head;
                } else {
                    last_seg_end->next = seg_head;
                }
                last_seg_end = node;
                node = next_seg_head;
            } else {
                _k = k - _k;
                reverseGroup(seg_head, _k, seg_head, next_seg_head);
                if (!head) {
                    return seg_head;
                } else {
                    last_seg_end->next = seg_head;
                    return head;
                }
            }
        } while (node);
        return head;
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
