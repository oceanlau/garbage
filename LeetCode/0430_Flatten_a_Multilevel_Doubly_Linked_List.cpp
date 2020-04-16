/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* flatten_end(Node* node) {
        Node* lastnode = NULL;
        while (node != NULL) {
            lastnode = node;
            Node* node_next = node->next;
            if (node->child) {
                Node* child_end = flatten_end(node->child);
                
                node->next = node->child;
                node->child->prev = node;
                node->child = NULL;
                
                if (node_next) {
                    child_end->next = node_next;
                    node_next->prev = child_end;
                }
            }
            node = node_next;
        }
        return lastnode;
    }
public:
    Node* flatten(Node* head) {
        flatten_end(head);
        return head;
    }
};
