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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = new ListNode();
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            
            ListNode* next_node = slow->next;
            slow->next = last;
            last = slow;
            slow = next_node;
        }
        ListNode* h1 = slow;
        ListNode* h2 = slow->next;
        slow->next = last;
        if (!fast->next) {
            h1 = last;
        }
        while (h1 && h2) {
            if (h1->val != h2->val) {
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};

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
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = NULL;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            ListNode* next_node = slow->next;
            slow->next = last;
            last = slow;
            slow = next_node;
        }
        ListNode* h1 = NULL;
        ListNode* h2 = slow->next;
        if (fast->next) {
            slow->next = last;
            h1 = slow;
        } else {
            h1 = last;
        }
        while (h1 && h2) {
            if (h1->val != h2->val) {
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        return !h1 && !h2;
    }
};
