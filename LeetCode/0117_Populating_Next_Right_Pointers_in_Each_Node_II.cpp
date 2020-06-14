/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* left = root;
        Node* dummy = new Node();
        while (left) {
            Node* parent = left;
            left = NULL;
            Node* last = dummy;
            while (parent) {
                if (!left) {
                    if (parent->left) {
                        left = parent->left;
                    } else if (parent->right) {
                        left = parent->right;
                    }
                }
                if (parent->left) {
                    last->next = parent->left;
                    last = parent->left;
                }
                if (parent->right) {
                    last->next = parent->right;
                    last = parent->right;
                }
                parent = parent->next;
            }
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    // connect children's first
    // then recurse on the left most child, use the next ptr(instead of queue)
    Node* connect(Node* root) {//left_most_parent
        Node* left_most_child = NULL;
        Node* node = NULL;
        Node* original_root = root;
        while(root) {
            if (root->left) {
                if (left_most_child == NULL) {
                    left_most_child = root->left;
                    node = root->left;
                } else {
                    node->next = root->left;
                    node = node->next;
                }
            }
            if (root->right) {
                if (left_most_child == NULL) {
                    left_most_child = root->right;
                    node = root->right;
                } else {
                    node->next = root->right;
                    node = node->next;
                }
            }
            root = root->next;
        }
        if (left_most_child) {
            connect(left_most_child);
        }
        return original_root;
    }
};
