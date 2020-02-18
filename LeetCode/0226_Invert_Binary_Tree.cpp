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
private:
    void _swap(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        swap(node->left, node->right);
        _swap(node->left);
        _swap(node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        _swap(root);
        return root;
    }
};
