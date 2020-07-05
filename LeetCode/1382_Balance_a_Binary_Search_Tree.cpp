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
    void inorder_traverse(TreeNode* root, vector<TreeNode*>& inorder) {
        if (root->left) {
            inorder_traverse(root->left, inorder);
        }
        inorder.push_back(root);
        if (root->right) {
            inorder_traverse(root->right, inorder);
        }
    }
    TreeNode* build(vector<TreeNode*>& inorder, int i, int j) {
        int mid = i + (j - i) / 2;
        TreeNode* root = inorder[mid];
        if (mid > i) {
            root->left = build(inorder, i, mid - 1);
        } else {
            root->left = NULL;
        }
        if (mid < j) {
            root->right = build(inorder, mid + 1, j);
        } else {
            root->right = NULL;
        }
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) {
            return root;
        }
        vector<TreeNode*> inorder;
        inorder_traverse(root, inorder);
        return build(inorder, 0, inorder.size() - 1);
    }
};
