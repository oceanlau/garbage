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
    TreeNode* _find_successor(TreeNode* p) {
        TreeNode* successor = p->right;
        if (successor) {
            while (successor->left) {
                successor = successor->left;
            }
        }
        return successor;
    }
    bool _find(TreeNode* node, TreeNode* p, TreeNode*& smallest) {
        if (!node) {
            return false;
        }
        if (node->val == p->val) {
            return true;
        }
        if (node->val > p->val) {
            if (!smallest || smallest->val > node->val) {
                smallest = node;
            }
        }
        return _find(node->left, p, smallest) || _find(node->right, p, smallest);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = _find_successor(p);
        if (successor) {
            return successor;
        }
        TreeNode* smallest = NULL;
        _find(root, p, smallest);
        return smallest;
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right != NULL) {
            p = p->right;
            while (p->left != NULL) {
                p = p->left;
            }
            return p;
        } else {
            TreeNode* target = NULL;
            while(root && root != p){
                if (root->val > p->val) {
                    target = root;
                    root = root->left;
                } else {
                    root = root->right;
                }
            }
            return target;
        }
    }
};
