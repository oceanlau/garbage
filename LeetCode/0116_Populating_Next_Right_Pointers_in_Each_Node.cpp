class Solution {
public:
    Node* connect(Node* root) {
        Node* node = root;
        while (node && node->left) {
            Node* last_right = NULL;
            Node* next_level = node->left;
            while (node) {
                if (last_right) {
                    last_right->next = node->left;
                }
                node->left->next = node->right;
                last_right = node->right;
                node = node->next;
            }
            node = next_level;
        }
        return root;
    }
};
