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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lh = 0;
        TreeNode* left = root->left;
        while (left) {
            lh ++;
            left = left->left;
        }
        int rh = 0;
        TreeNode* right = root->right;
        while (right) {
            rh ++;
            right = right->right;
        }
        if (lh == rh) {
            return pow(2, lh + 1) - 1;
        }
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
};
