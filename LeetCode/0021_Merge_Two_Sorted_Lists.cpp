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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 && l2) {
            if (l1->val > l2->val) {
                swap(l1, l2);
            }
        } else if (l1) {
            return l1;
        } else {
            return l2;
        }
        ListNode* head = l1;
        ListNode** cur_ptr = &head;
        while (l1 || l2) {
            if (l1) {
                if (l2) {
                    if (l1->val > l2->val) {
                        *cur_ptr = l2;
                        cur_ptr = &(l2->next);
                        l2 = l2->next;
                    } else {
                        *cur_ptr = l1;
                        cur_ptr = &(l1->next);
                        l1 = l1->next;
                    }
                } else {
                    *cur_ptr = l1;
                    break;
                }
            } else {
                *cur_ptr = l2;
                break;
            }
        }
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* cur = NULL;
        while(l1 != NULL || l2 != NULL) {
            if (l1 == NULL || (l1 != NULL && l2 != NULL && l2->val < l1->val)) {
                if (head == NULL) {
                    head = l2;
                    cur = head;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            } else {
                if (head == NULL) {
                    head = l1;
                    cur = head;
                } else {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            } 
        }
        if (cur != NULL) {
            cur->next = NULL;
        }
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // error without NULL
        ListNode* h = NULL;
        ListNode* loop = NULL;
        while(true) {
            if (!l1 && !l2) {
                break;
            }
            // error without !!l2
            if (!l1 || (!!l2 && l1->val >= l2->val)) {
                if(!h) {
                    loop = l2;
                    h = loop;
                } else {
                    loop->next = l2;
                    loop = loop->next;
                }
                l2 = l2->next;
            } else {
                if(!h) {
                    loop = l1;
                    h = loop;
                } else {
                    loop->next = l1;
                    loop = loop->next;
                }
                l1 = l1->next;
            }
            
        }
        return h;
    }
};
