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
    int count(ListNode* l) {
        int cnt = 0;
        while (l) {
            l = l->next;
            cnt ++;
        }
        return cnt;
    }
    ListNode* add(ListNode* l1, ListNode* l2, int more) {
        if (!l1 || !l2) {
            return l1;
        }
        ListNode* head = new ListNode(l1->val);
        if (more == 0) {
            head->val += l2->val;
            head->next = add(l1->next, l2->next, 0);
        } else {//more > 0
            head->next = add(l1->next, l2, more - 1);
        }
        if (head->next && head->next->val >= 10) {
            head->next->val -= 10;
            head->val += 1;
        }
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = count(l1);
        int n2 = count(l2);
        ListNode* head = n1 > n2 ? add(l1, l2, n1 - n2) : add(l2, l1, n2 - n1);
        if (head->val < 10) {
            return head;
        } else {
            ListNode* newhead = new ListNode(1);
            head->val -= 10;
            newhead->next = head;
            return newhead;
        }
    }
};
