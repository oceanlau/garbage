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
    void _dfs(TreeNode* node, int depth, vector<int>& results) {
        if (!node) {
            return;
        }
        if (depth + 1 > results.size()) {
            results.push_back(node->val);
        }
        _dfs(node->right, depth + 1, results);
        _dfs(node->left, depth + 1, results);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        _dfs(root, 0, results);
        return results;
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
