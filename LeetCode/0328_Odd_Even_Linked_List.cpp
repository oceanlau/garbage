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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* even_head = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        while (even) {
            odd->next = even->next;
            even->next = NULL;
            if (odd->next) {
                odd = odd->next;
                even->next = odd->next;
            }
            even = even->next;
        }
        odd->next = even_head;
        return head;
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* node = head;
        ListNode* evenhead = node->next;
        ListNode* evennode = evenhead;
        while (evennode) {
            ListNode* nextodd = evennode->next;
            node->next = nextodd;
            if (nextodd) {
                //make sure node is not null
                node = node->next;
                evennode->next = nextodd->next;
            } else {
                evennode->next = NULL;
            }
            evennode = evennode->next;
        }
        node->next = evenhead;
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* oddnode = head;
        ListNode* evenhead = head->next;
        ListNode* evennode = head->next;
        while (evennode) {
            oddnode->next = evennode->next;
            if (oddnode->next) {
                oddnode = oddnode->next;
                evennode->next = oddnode->next;
            } else {
                evennode->next = NULL;
            }
            evennode = evennode->next;
        }
        oddnode->next = evenhead;
        return head;
    }
};
