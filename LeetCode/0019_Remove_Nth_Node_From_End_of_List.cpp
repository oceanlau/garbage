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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        ListNode* beforen = head;
        while (n-- > 0) {
            node = node->next;
        }
        if (!node) {
            return beforen->next;
        }
        while (node->next != NULL) {
            beforen = beforen->next;
            node = node->next;
        }
        ListNode* aftern = beforen->next->next;
        beforen->next = aftern;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        queue<ListNode*> n_nodes;
        
        while(tail) {
            n_nodes.push(tail);
            if(n_nodes.size() > n + 1) {
                n_nodes.pop();
            }
            tail = tail->next;
        }
        if (n_nodes.size() == n + 1) {
            ListNode* node_prev = n_nodes.front();
            if (n_nodes.size() > 2) {
                n_nodes.pop();
                n_nodes.pop();
                ListNode* node_next = n_nodes.front();
                node_prev->next = node_next;
            } else {
                node_prev->next = NULL;
            }
        } else if (n_nodes.size() > 0) {
            return head->next;
        }
        return head;
    }
};
