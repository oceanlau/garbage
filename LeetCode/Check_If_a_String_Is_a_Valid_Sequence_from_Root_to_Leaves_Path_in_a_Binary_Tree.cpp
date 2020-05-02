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
    bool isValid(TreeNode* node, int i, vector<int>& arr) {
        if (!node || node->val != arr[i]) {
            return false;
        }
        if (++i == arr.size()) {
            if (!node->left && !node->right) {
                return true;
            } else {
                return false;
            }
        }
        return isValid(node->left, i, arr) || isValid(node->right, i, arr); 
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (arr.size() == 0) {
            return true;
        }
        return isValid(root, 0, arr);
    }
};
