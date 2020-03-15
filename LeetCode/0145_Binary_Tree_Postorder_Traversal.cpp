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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while (s.size() > 0) {
            TreeNode* last = s.top();
            if (last->left) {
                s.push(last->left);
                last->left = NULL;
            } else if (last->right) {
                s.push(last->right);
                last->right = NULL;
            } else {
                res.push_back(last->val);
                s.pop();
            }
        }
        return res;
    }
};
