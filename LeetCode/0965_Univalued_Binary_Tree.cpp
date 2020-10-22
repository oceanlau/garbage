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
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isUnivalTree(root->left, root->val) && isUnivalTree(root->right, root->val);
    }
    bool isUnivalTree(TreeNode* root, int val) {
        if (!root) {
            return true;
        } else if (root->val == val) {
            return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
        }
        return false;
    }
};
