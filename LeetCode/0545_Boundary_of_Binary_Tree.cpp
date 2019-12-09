/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//先找root左子树的left bound (只有最左边一条和最左边一条没有left child时的right child算) 和 leaf
//记录下res array size
//再找右子树,right bound和leaf, clockwise
//旋转右边的结果
class Solution {
private:
    void _dfs_left(TreeNode* node, vector<int>& res, bool is_res) {
        if (node == NULL) {
            return;
        }
        if (is_res) {
            res.push_back(node->val);
            if (node->left) {
                _dfs_left(node->left, res, true);
                //有leftchild，right以后的都不算了！
                _dfs_left(node->right, res, false);
            } else {
                _dfs_left(node->right, res, true);
            }
        } else if (node->left == NULL && node->right == NULL) {
            res.push_back(node->val);
        } else {
            _dfs_left(node->left, res, false);
            _dfs_left(node->right, res, false);
        }
    }
    
    void _dfs_right(TreeNode* node, vector<int>& res, bool is_res) {
        if (node == NULL) {
            return;
        }
        if (is_res) {
            res.push_back(node->val);
            if (node->right) {
                _dfs_right(node->right, res, true);
                _dfs_right(node->left, res, false);
            } else {
                _dfs_right(node->left, res, true);
            }
        } else if (node->left == NULL && node->right == NULL) {
            res.push_back(node->val);
        } else {
            _dfs_right(node->left, res, false);
            _dfs_right(node->right, res, false);
        }
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root) {
            res.push_back(root->val);
            _dfs_left(root->left, res, true);
            int left_end = res.size();
            _dfs_right(root->right, res, true);
            reverse(res.begin() + left_end, res.end());
        }
        return res;
    }
};
