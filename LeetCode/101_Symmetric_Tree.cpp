//iter
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode*> ltr;
        ltr.push(root->left);
        queue<TreeNode*> rtl;
        rtl.push(root->right);
        while(!ltr.empty() && !rtl.empty()) {
            TreeNode* l = ltr.front();
            ltr.pop();
            TreeNode* r = rtl.front();
            rtl.pop();
            if (l == NULL && r == NULL) {
                continue;
            }
            if (l == NULL || r == NULL) {
                return false;
            }
            if (l->val != r->val) {
                return false;
            }
            ltr.push(l->left);
            ltr.push(l->right);
            rtl.push(r->right);
            rtl.push(r->left);
        }
        if (!ltr.empty() || !rtl.empty()) {
            return false;
        }
        return true;
    }
};

//recur
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
    bool isSymmetricNodes(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL) {
            return true;
        }
        if (l == NULL || r == NULL) {
            return false;
        }
        if (l->val != r->val) {
            return false;
        }
        return isSymmetricNodes(l->left, r->right) && isSymmetricNodes(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL || isSymmetricNodes(root->left, root->right)) {
            return true;
        }
        return false;
    }
};
