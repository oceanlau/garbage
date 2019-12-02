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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        TreeNode** parent = NULL;
        while (node != NULL) {
            if (node->val < val) {
                parent = &(node->right);
                node = node->right;
            } else {
                parent = &(node->left);
                node = node->left;
            }
        }
        if (parent) {
            *parent = new TreeNode(val);
        } else {
            node = new TreeNode(val);
            return node;
        }
        return root;
    }
};
