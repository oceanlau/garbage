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
    pair<int, int> _rob(TreeNode* node) {
        if (!node) {
            return make_pair(0, 0);
        }
        pair<int, int> l = _rob(node->left);
        pair<int, int> r = _rob(node->right);
        return make_pair(node->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second));
    }
public:
    int rob(TreeNode* root) {
        // each child has a robbed max and unrobbed max
        pair<int, int> robbed_unrobbed = _rob(root);
        return max(robbed_unrobbed.first, robbed_unrobbed.second);
    }
};
