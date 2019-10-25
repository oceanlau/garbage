//96% 100%
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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        sum -= root->val;
        if (sum == 0 && root->left == NULL && root->right == NULL) {
            return true;
        }
        return hasPathSum(root->left, sum) ||  hasPathSum(root->right, sum);
    }
};

// 96% 93%
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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        sum -= root->val;
        if (sum == 0 && root->left == NULL && root->right == NULL) {
            return true;
        }
        if (root->left != NULL && hasPathSum(root->left, sum)) {
            return true;
        }
        if (root->right != NULL && hasPathSum(root->right, sum)) {
            return true;
        }
        return false;
    }
};
