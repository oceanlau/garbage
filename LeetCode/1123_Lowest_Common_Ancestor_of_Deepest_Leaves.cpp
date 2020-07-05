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
    pair<TreeNode*, int> _dfs(TreeNode* root, int depth) {
        pair<TreeNode*, int> l = {root, depth};
        pair<TreeNode*, int> r = {root, depth};
        if (root->left) {
            l = _dfs(root->left, depth + 1);
        }
        if (root->right) {
            r = _dfs(root->right, depth + 1);
        }
        if (l.second > r.second) {
            return l;
        } else if (l.second < r.second) {
            return r;
        }
        return {root, l.second};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // dfs
        // collect (lca proposed, deepest depth) from left and right children
        // if left deepest depth == right deepest depth, update the lca proposed
        // else return deeper one
        // if no children, return itself
        if (!root) {
            return root;
        }
        pair<TreeNode*, int> proposal = _dfs(root, 0);
        return proposal.first;
    }
};
