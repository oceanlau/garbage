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
    pair<TreeNode*, TreeNode*> flat(TreeNode* node) {
        pair<TreeNode*, TreeNode*> l = {NULL, NULL};
        pair<TreeNode*, TreeNode*> r = {NULL, NULL};
        if (node->left) {
            l = flat(node->left);
            node->left = NULL;
            if (node->right) {
                r = flat(node->right);
                node->right = l.first;
                l.second->right = r.first;
                return {node, r.second};
            } else {
                node->right = l.first;
                return {node, l.second};
            }
        } else if (node->right) {
            r = flat(node->right);
            node->right = r.first;
            return {node, r.second};
        } else {
            return {node, node};
        }
    }
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        flat(root);
    }
};
