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
    bool _isValid(TreeNode* root, vector<int>& arr, int i) {
        if (root->val == arr[i]) {
            if (i == arr.size() - 1) {
                if (!root->left && !root->right) {
                    return true;
                }
                return false;
            }
            return (root->left && _isValid(root->left, arr, i + 1)) || (root->right && _isValid(root->right, arr, i + 1));
        }
        return false;
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (!root || arr.empty()) {
            return false;
        }
        return _isValid(root, arr, 0);
    }
};
