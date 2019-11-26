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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right != NULL) {
            p = p->right;
            while (p->left != NULL) {
                p = p->left;
            }
            return p;
        } else {
            TreeNode* target = NULL;
            while(root && root != p){
                if (root->val > p->val) {
                    target = root;
                    root = root->left;
                } else {
                    root = root->right;
                }
            }
            return target;
        }
    }
};
