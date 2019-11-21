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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() != 0) {
            int q_size = q.size();
            while (q_size > 0) {
                TreeNode* cur = q.front();
                if (q_size == 1) {
                    res.push_back(cur->val);
                }
                if (cur->left != NULL) {
                    q.push(cur->left);
                }
                if (cur->right != NULL) {
                    q.push(cur->right);
                }
                q.pop();
                q_size --;
            }
        }
        return res;
    }
};
