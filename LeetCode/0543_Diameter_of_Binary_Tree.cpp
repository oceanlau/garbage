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
    int _longestPathFrom(TreeNode* node, int& diameter) {
        int l = 0;
        int r = 0;
        if (node->left) {
            l = _longestPathFrom(node->left, diameter) + 1;
        }
        if (node->right) {
            r = _longestPathFrom(node->right, diameter) + 1;
        }
        int longest = max(l, r);
        diameter = max(longest, diameter);
        diameter = max(l + r, diameter);
        return longest;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        if (root) {
            _longestPathFrom(root, diameter);
        }
        return diameter;
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
