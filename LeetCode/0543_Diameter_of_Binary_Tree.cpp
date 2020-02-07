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
    int getLongest(TreeNode* node, int& longest){
        if (node == NULL) {
            return 0;
        }
        int l = 1 + getLongest(node->left, longest);
        int r = 1 + getLongest(node->right, longest);
        if (l + r - 1 > longest) {
            longest = l + r - 1;
        }
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int longest = 1;
        getLongest(root, longest);
        return longest - 1;
    }
};
