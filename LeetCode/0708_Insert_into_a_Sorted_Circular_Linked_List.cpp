/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* inserted = new Node(insertVal);
        if (!head) {
            inserted->next = inserted;
            return inserted;
        }
        Node* prev = head;
        Node* next = prev->next;
        bool flag = false;
        //add in between or add at tail
        do {
            if (prev->val <= next->val) {
                if (insertVal >= prev->val && insertVal <= next->val) {
                    prev->next = inserted;
                    inserted->next = next;
                    flag = true;
                    break;
                }
            } else {
                if (insertVal <= next->val || insertVal >= prev->val) {
                    prev->next = inserted;
                    inserted->next = next;
                    flag = true;
                    break;
                }
            }
            prev = prev->next;
            next = next->next;
        } while (prev != head);
        
        // when all node are same value and not equal to inserval, cannot be inserted by above comparisons
        // tricky: insert any where
        if (!flag) {
            prev->next = inserted;
            inserted->next = next;
        }
        return head;
    }
};
