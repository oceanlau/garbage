/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    void _dfs(Node* node, Node*& DLL_root, Node*& DLL_last) {
        if (node->left) {
            _dfs(node->left, DLL_root, DLL_last);
        }
        if (DLL_root == NULL) {
            DLL_root = node;
        }
        if (DLL_last) {
            DLL_last->right = node;
            node->left = DLL_last;
        }
        DLL_last = node;
        if (node->right) {
            _dfs(node->right, DLL_root, DLL_last);
        }
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        Node* DLL_root = NULL;
        Node* DLL_last = NULL;
        _dfs(root, DLL_root, DLL_last);
        DLL_root->left = DLL_last;
        DLL_last->right = DLL_root;
        return DLL_root;
    }
};

//60% 10%
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:    
    void _dfs(Node* node, Node*& first_node, Node*& last_node) {
        if (node->left != NULL) {
            _dfs(node->left, first_node, last_node);
        }
        Node* new_node = new Node(node->val, last_node, NULL);
        if (last_node != NULL) {
            last_node->right = new_node;
        }
        if (first_node == NULL) {
            first_node = new_node;
        }
        last_node = new_node;
        if (node->right != NULL) {
            _dfs(node->right, first_node, last_node);
        }
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        Node* first_node = NULL;
        Node* last_node = NULL; // the last inorder ele during traversal
        _dfs(root, first_node, last_node);
        if (last_node != NULL) {
            last_node->right = first_node;
            first_node->left = last_node;
        }
        return first_node;
        
        // DFS
        // db linked list is same order as dfs traversal seq
        // last_node pass in by ref
        // last_node->right = new_node last_node = new_node if no first_node, first_node = new_node
        //
        // link last_node - first
    }
};
