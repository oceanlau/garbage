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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        ListNode* node = head;
        dummy->next = node;
        while (node && node->next) {
            ListNode* next = node->next;
            ListNode* next_next = next->next;
            next->next = node;
            node->next = next_next;
            prev->next = next;
            
            prev = node;
            node = next_next;
        }
        return dummy->next;
    }
};

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
