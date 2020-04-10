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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int maxwidth = 1;
        while (!q.empty()) {
            int q_size = q.size();
            int left = -1;
            
            //find min of cur row, all subtract it to avoid int overflow
            pair<TreeNode*, int> cur = q.front();
            int min_cur = cur.second;
            
            while (q_size > 0) {
                cur = q.front();
                TreeNode* cur_node = cur.first;
                q.pop();
                if (cur_node->left) {
                    int pos = 2 * (cur.second - min_cur + 1);
                    if (left == -1) {
                        left = pos;
                    } else {
                        maxwidth = max(pos - left + 1, maxwidth);
                    }
                    q.push(make_pair(cur_node->left, pos));
                }
                if (cur_node->right) {
                    int pos = 2 * (cur.second - min_cur + 1) + 1;
                    if (left == -1) {
                        left = pos;
                    } else {
                        maxwidth = max(pos - left + 1, maxwidth);
                    }
                    q.push(make_pair(cur_node->right, pos));
                }
                q_size --;
            }
        }
        return maxwidth;
    }
};
