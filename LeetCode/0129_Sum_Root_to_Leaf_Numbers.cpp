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
    void _dfs(TreeNode* node, int cur, int& sum) {
        cur = cur * 10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            sum += cur;
        } else {
            if (node->left != NULL) {
                _dfs(node->left, cur, sum);
            }
            if (node->right != NULL) {
                _dfs(node->right, cur, sum);
            }
        }
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sum = 0;
        _dfs(root, 0, sum);
        return sum;
    }
};
