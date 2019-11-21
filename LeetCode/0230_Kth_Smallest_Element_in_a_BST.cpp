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
    int kthSmallest(TreeNode* root, int k) {
        int target;
        dfs(root, k, target);
        return target;
    }
    void dfs(TreeNode* node, int& k, int& target) {
        if (node == NULL) {
            return;
        }
        dfs(node->left, k, target);
        if (k == 0) {
            return;
        } else if (--k == 0) {
            target = node->val;
            return;
        }
        dfs(node->right, k, target);
    }
};
