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
    void _dfs(TreeNode* node, int cur, int& result) {
        if (!node) {
            return;
        }
        cur += node->val;
        if (!node->left && !node->right) {
            result += cur;
            return;
        }
        _dfs(node->left, cur * 10, result);
        _dfs(node->right, cur * 10, result);
    }
public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        _dfs(root, 0, result);
        return result;
    }
};
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
