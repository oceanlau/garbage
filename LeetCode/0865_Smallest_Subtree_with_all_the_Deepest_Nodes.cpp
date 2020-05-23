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
    pair<int, TreeNode*> _dfs(TreeNode* node) {
        if (node == NULL) {
            return make_pair(0, node);
        }
        pair<int, TreeNode*> l = _dfs(node->left);
        pair<int, TreeNode*> r = _dfs(node->right);
        if (l.first > r.first) {
            return make_pair(l.first + 1, l.second);
        } else if (l.first < r.first) {
            return make_pair(r.first + 1, r.second);
        }
        return make_pair(r.first + 1, node);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode*> res = _dfs(root);
        return res.second;
    }
};
