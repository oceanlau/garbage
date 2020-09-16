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
    int _dfs(TreeNode* node, int depth) {
        int max_depth = depth;
        if (node->left) {
            max_depth = max(max_depth, _dfs(node->left, depth + 1));
        }
        if (node->right) {
            max_depth = max(max_depth, _dfs(node->right, depth + 1));
        }
        return max_depth;
    }
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return _dfs(root, 1);
    }
};
