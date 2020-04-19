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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool end_flag = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                end_flag = true;
            } else if (end_flag) {
                return false;
            } else {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
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
public:
    bool isCompleteTree(TreeNode* root) {
        // BFS: in the last lvl. cannot be nodes after null
        // DFS: pass a ref of max lvl. from left to right max lvl can decrease but not increase
        queue<TreeNode*> q;
        q.push(root);
        bool empty_after = false;
        while (q.size() != 0) {
            int q_size = q.size();
            while (q_size != 0) {
                TreeNode* node = q.front();
                q.pop();
                if (node == NULL) {
                    empty_after = true;
                } else {
                    if (empty_after) {
                        return false;
                    }
                    q.push(node->left);
                    q.push(node->right);
                }
                q_size --;
            }
        }
        return true;
    }
};
