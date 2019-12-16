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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool is_dir_lr = true;
        while(q.size() > 0) {
            int q_size = q.size();
            int i = is_dir_lr ? 0 : q_size - 1;
            vector<int> row (q_size, -1);
            while (i >= 0 && i <= q_size - 1) {
                TreeNode* cur = q.front();
                q.pop();
                row[i] = cur->val;
                is_dir_lr ? i++ : i--;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            is_dir_lr = !is_dir_lr;
            res.push_back(row);
        }
        return res;
    }
};
