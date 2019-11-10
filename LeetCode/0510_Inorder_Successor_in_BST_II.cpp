//5%? 100%
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // locate in the right the left most child
        if (node->right != NULL) {
            node = node->right;
            while(node->left != NULL) {
                node = node->left;
            }
            return node;
        } else {
        // if none, locate the first right side parent
        // if none return NULL
            while (node->parent != NULL && node->parent->right == node) {
                node = node->parent;
            }
            return node->parent;
        }
    }
};
