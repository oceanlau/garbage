//98% 91%
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
    bool _dfs(TreeNode* node, int min, int max) {
        //if min is -1 or node val > min legal
        if (min != -1 && node->val <= min) {
            return false;
        }
        //if max is -1 or node val < max legal
        //otherwise return false
        if (max != -1 && node->val >= max) {
            return false;
        }
        //if left exisit, _dfs(left, min, new max) must return true
        if (node->left != NULL && !_dfs(node->left, min, node->val)) {
            return false;
        }
        //if right exisit, _dfs(left, new min, max) must return true
        //otherwise return false
        if (node->right != NULL && !_dfs(node->right, node->val, max)) {
            return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return _dfs(root, -1, -1);
    }
};
