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
    int _count(TreeNode* node, int& x, int& l, int& r) {
        if (node == NULL) {
            return 0;
        }
        int left = 0;
        int right = 0;
        if (node->left) {
            left = _count(node->left, x, l, r);
        }
        if (r != -1) {
            return -1;
        }
        if (node->right) {
            right = _count(node->right, x, l, r);
        }
        if (node->val == x) {
            l = left;
            r = right;
        }
        return 1 + left + right;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int l = -1;
        int r = -1;
        _count(root, x, l, r);
        int maxone = max(l, r);
        maxone = max(n - l - r - 1, maxone);
        return maxone > (n - maxone);
    }
};
