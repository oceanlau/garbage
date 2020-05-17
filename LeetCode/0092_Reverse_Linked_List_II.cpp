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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* seg1_end = head;
        ListNode* seg2_end = head;
        int _m = m;
        while (_m > 1) {
            if (_m - 1 > 1) {
                seg1_end = seg1_end->next;
            }
            seg2_end = seg2_end->next;
            _m --;
        }
        int _n = n - m + 1;
        ListNode* seg2_prev = NULL;
        ListNode* seg2_node = seg2_end;
        ListNode* seg2_next = NULL;
        while (_n > 0) {
            seg2_next = seg2_node->next;
            seg2_node->next = seg2_prev;
            seg2_prev = seg2_node;
            seg2_node = seg2_next;
            _n --;
        }
        seg2_end->next = seg2_node;
        if (m > 1) {
            seg1_end->next = seg2_prev;
            return head;
        }
        return seg2_prev;
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //ListNode**
        ListNode* ptr_i = head;
        ListNode** ptr_to_sub_head = &head;
        int i = 1;
        ListNode* sub_head = NULL;
        ListNode* sub_tail = NULL;
        ListNode* tmp_next = NULL;
        ListNode* tmp_last = NULL;
        while (i <= n) {
            if (i == m - 1) {
                ptr_to_sub_head = &(ptr_i->next);
                tmp_last = ptr_i;
            } else if (i >= m) {
                if (i == m) {
                    sub_tail = ptr_i;
                }
                if (i == n) {
                    sub_head = ptr_i;
                }
                //save the 'next' value of i-th node
                tmp_next = ptr_i->next;
                //assign the ptr_to_last to the 'next' of i-th node
                ptr_i->next = tmp_last;
                tmp_last = ptr_i;
                //move on to the saved 'next' value of i-th node
                ptr_i = tmp_next;
                i++;
                continue;
            }
            
            ptr_i = ptr_i->next;
            i++;
        }
        // put the head and tail of the reversed list in place
        *ptr_to_sub_head = sub_head;
        sub_tail->next = ptr_i;
        return head;
    }
};
