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

// level 1: -1,5    3,4    0 (each pair, 2 * 2^0)
// level 2: -1,3,4,5    0    (each pair, 2 * 2^1)
// level 3: -1,0,3,4,5       (each pair, 2 * 2^2)
class Solution {
private:
    ListNode* get_next_part(ListNode* h, int part_len) {
        while (part_len > 1 && h) {
            h = h->next;
            part_len --;
        }
        //cut off
        if (!h) {
            return NULL;
        }
        //if (part_len == 1) {
        ListNode* next_part_h = h->next;
        h->next = NULL;
        return next_part_h;
    }
    ListNode* merge(ListNode* l, ListNode* r, ListNode* prev) {
        while (l && r) {
            if (l->val <= r->val) {
                prev->next = l;
                l = l->next;
            } else {
                prev->next = r;
                r = r->next;
            }
            prev = prev->next;
        }
        if (l) {
            prev->next = l;
        } else {
            prev->next = r;
        }
        //move to the end
        while (prev->next) {
            prev = prev->next;
        }
        return prev;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        bool done = false;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* l;
        ListNode* r;
        ListNode* prev;
        for (int part_len = 1; !done; part_len *= 2) {
            l = dummy->next;
            prev = dummy;
            while (l) {
                r = get_next_part(l, part_len);
                if (!r && l == dummy->next) {
                    done = true;
                }
                ListNode* next_l = get_next_part(r, part_len);
                prev = merge(l, r, prev);
                l = next_l;
            }
        }
        return dummy->next;
    }
};
