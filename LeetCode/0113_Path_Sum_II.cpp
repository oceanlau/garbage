//67% 92%
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
    void _dfs(TreeNode* node, int sum, vector<vector<int>>& res, vector<int>& current) {
        if (node == NULL) {
            return;
        }
        sum -= node->val;
        current.push_back(node->val);
        if (sum == 0 && node->left == NULL && node->right == NULL) {
            res.push_back(current);
            current.pop_back();
            return;
        }
        _dfs(node->left, sum, res, current);
        _dfs(node->right, sum, res, current);
        current.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> current;
        _dfs(root, sum, res, current);
        return res;
    }
};
