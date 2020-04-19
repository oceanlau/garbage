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
    void _del(TreeNode* node, vector<TreeNode*>& roots, unordered_set<int>& to_del, bool is_root, TreeNode** ptr) {
        if (!node) {
            return;
        }
        if (to_del.count(node->val)) {
            if (ptr) {
                *ptr = NULL;
            }
            _del(node->left, roots, to_del, true, &(node->left));
            _del(node->right, roots, to_del, true, &(node->right));
            return;
        }
        if (is_root) {
            roots.push_back(node);
        }
        _del(node->left, roots, to_del, false, &(node->left));
        _del(node->right, roots, to_del, false, &(node->right));
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> roots;
        unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        _del(root, roots, to_del, true, NULL);
        return roots;
    }
};
