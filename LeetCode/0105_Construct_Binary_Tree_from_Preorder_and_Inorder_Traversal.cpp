// 80% 95%
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
    int preorder_idx = 0;
    TreeNode* _build_tree(vector<int>& preorder, vector<int>& inorder, int i, int j) {
        int root_val = preorder[preorder_idx];
        TreeNode* node = new TreeNode(root_val);
        if (preorder_idx == preorder.size() - 1){
            return node;
        }
        int k = i;
        for (; k <= j; k ++) {
            if (inorder[k] == root_val) {
                break;
            }
        }
        if (k-i == 0) {
            node->left = NULL;
        } else {
            preorder_idx ++;
            node->left = _build_tree(preorder, inorder, i, k-1);
        }
        if (j-k == 0) {
            node->right = NULL;
        } else {
            preorder_idx ++;
            node->right = _build_tree(preorder, inorder, k+1, j);
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        TreeNode* node = _build_tree(preorder, inorder, 0, inorder.size() - 1);
        return node;
    }
};
