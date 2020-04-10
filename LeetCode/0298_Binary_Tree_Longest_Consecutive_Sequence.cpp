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
    int longestConsecutiveIncluding(TreeNode* node, int& peak) {
        if (!node) {
            return 0;
        }
        int l = 1;
        if (node->left) {
            l += longestConsecutiveIncluding(node->left, peak);
            if (node->left->val - node->val != 1) {
                l = 1;
            }
        }
        int r = 1;
        if (node->right) {
            r += longestConsecutiveIncluding(node->right, peak);
            if (node->right->val - node->val != 1) {
                r = 1;
            }
        }
        peak = max(peak, l);
        peak = max(peak, r);
        return max(l, r);
    }
public:
    int longestConsecutive(TreeNode* root) {
        int peak = 0;
        longestConsecutiveIncluding(root, peak);
        return peak;
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
private:
    int _dfs(TreeNode* node, int len) {
        if (node == NULL) {
            return 0;
        }
        len ++;
        int child_len = 0;
        if (node->left) {
            if (node->left->val - node->val  == 1) {
                child_len = _dfs(node->left, len);
            } else {
                child_len = _dfs(node->left, 0);
            }
        }
        if (node->right) {
            if (node->right->val - node->val  == 1) {
                child_len = max(child_len, _dfs(node->right, len));
            } else {
                child_len = max(child_len, _dfs(node->right, 0));
            }
        }
        return max(len, child_len);
    }
public:
    int longestConsecutive(TreeNode* root) {
        // each dfs step. pass len in. reset len if it is not contious. return max(len, children return) 
        return _dfs(root, 0); 
    }
};
