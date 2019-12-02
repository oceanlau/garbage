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
    int _get_height(TreeNode* node) {
        int l = 0;
        if (node->left) {
            l = _get_height(node->left);
        }
        int r = 0;
        if (node->right) {
            r = _get_height(node->right);
        }
        return 1 + max(l, r);
    }
    void _dfs(TreeNode* node, int l, int r, vector<vector<string>>& res, int depth) {
        int mid = l + (r - l) / 2;
        res[depth][mid] = to_string(node->val);
        if (node->left) {
            _dfs(node->left, l, mid - 1, res, depth + 1);
        }
        if (node->right) {
            _dfs(node->right, mid + 1, r, res, depth + 1);
        }
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        int h = _get_height(root);
        int w = pow(2, h) - 1;
        vector<vector<string>> res(h, vector<string>(w, ""));
        _dfs(root, 0, w - 1, res, 0);
        return res;
    }
};
