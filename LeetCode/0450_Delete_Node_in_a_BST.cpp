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
