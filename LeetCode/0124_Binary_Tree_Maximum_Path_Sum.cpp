//84% 66%
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
    
    int maxPathSumFinder(TreeNode* node, int& maxSum) {
        if (node == NULL) {
            return 0;
        }
        int l = maxPathSumFinder(node->left, maxSum);
        int r = maxPathSumFinder(node->right, maxSum);
        int maxChildSum = node->val + max(l, r);
        if (node->val > maxChildSum) {
            maxChildSum = node->val;
        }
        int maxCurSum = max(maxChildSum, node->val + l + r);
        //use node / node - node->left / node - node->right / node->left - node - node->right to update maxSum
        if (maxCurSum > maxSum) {
            maxSum = maxCurSum;
        }
        //return the max of node - node->left / node - node->right for future potential maximum
        return maxChildSum;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumFinder(root, maxSum);
        return maxSum;
    }
};
