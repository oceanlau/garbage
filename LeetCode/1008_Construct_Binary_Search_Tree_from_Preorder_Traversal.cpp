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
    TreeNode* _dfs(vector<int>& preorder, int& i, int l, int r) {
        if (i >= preorder.size()) {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[i++]);
        if (i < preorder.size() && preorder[i] < node->val && preorder[i] > l) {
            node->left = _dfs(preorder, i, l, node->val);
        }
        if (i < preorder.size() && preorder[i] > node->val && preorder[i] < r) {
            node->right = _dfs(preorder, i, node->val, r);
        }
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return _dfs(preorder, i, INT_MIN, INT_MAX);
    }
};
