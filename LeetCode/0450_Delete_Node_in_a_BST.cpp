/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool _delete_node(TreeNode* cur, TreeNode* parent, int key) {
        if (!cur) {
            return false;
        }
        if (cur->val == key) {
            if (!cur->left) {
                if (parent->left == cur) {
                    parent->left = cur->right;
                } else {
                    parent->right = cur->right;
                }
            } else {
                int largest_lesser = _find_del_largest(cur);
                cur->val = largest_lesser;
            }
            return true;
        }
        return _delete_node(cur->left, cur, key) || _delete_node(cur->right, cur, key);
    }
    int _find_del_largest(TreeNode* parent) {
        TreeNode* cur = parent->left;
        TreeNode** r = &(parent->left);
        while (cur->right) {
            r = &(cur->right);
            cur = cur->right;
        }
        *r = cur->left;
        return cur->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        if (root->val == key) {
            if (!root->left) {
                return root->right;
            }
            int largest_lesser = _find_del_largest(root);
            root->val = largest_lesser;
        } else {
            _delete_node(root, NULL, key);
        }
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // textbook: complicated code
        // leaf node, just del it
        // one child, short cut it
        // two children, find inorder successor
        
        // recusively find val, if ->right exists, swap with inorder successor and continue find and del
        // if not, return ->left (dont care if it exists at all) as current node
        if (root == NULL) {
            return NULL;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->right) {
                TreeNode* inorder_suc = root->right;
                while (inorder_suc->left) {
                    inorder_suc = inorder_suc->left;
                }
                swap(root->val, inorder_suc->val);
                root->right = deleteNode(root->right, key);
                return root;
            } else {
                TreeNode* next = root->left;
                delete root;
                return next;
            }
        }
        return root;
    }
};
