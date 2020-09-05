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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int smaller = min(p->val, q->val);
        int larger = max(p->val, q->val);
        while (true) {
            if (root->val > larger) {
                root = root->left;
            } else if (root->val < smaller) {
                root = root->right;
            } else {
                break;
            }
        }
        return root;
    }
};
