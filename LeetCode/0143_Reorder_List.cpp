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
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            } else {
                break;
            }
            slow = slow->next;
        }
        ListNode* node = slow->next;
        slow->next = NULL;
        ListNode* lastnode = NULL;
        while (node) {
            ListNode* nextnode = node->next;
            node->next = lastnode;
            lastnode = node;
            node = nextnode;
        }
        
        node = head;
        while (lastnode) {
            ListNode* node_next = node->next;
            ListNode* lastnode_next = lastnode->next;
            node->next = lastnode;
            lastnode->next = node_next;
            node = node_next;
            lastnode = lastnode_next;
        }
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
    void reorderList(ListNode* head) {
        //watch the edge case
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        // tricky way to find middle
        while (p2->next != NULL && p2->next->next !=NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        // odd length seq, put mid in the last, so put part2 one past mid point
        // here p2 takes another meaning
        p2 = p1->next;
        // remember to cut off!
        p1->next = NULL;
        
        //using last/cur/next ptrs to reverse list
        ListNode* last = NULL;
        while (p2 != NULL) {
            ListNode* cur = p2;
            p2 = cur->next;
            cur->next = last;
            last = cur;
        }
        
        //simple merge
        p1 = head;
        p2 = last;
        // odd length seq, put mid in the last, so when p1 exist, p2 may not, check p2
        while (p2 != NULL) {
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
    }
};
