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
    bool _isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        }
        if (s->val != t->val) {
            return false;
        }
        return _isSame(s->left, t->left) && _isSame(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (_isSame(s, t)) {
            return true;
        }
        return s && ((s->left && isSubtree(s->left, t)) || (s->right && isSubtree(s->right, t)));
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL || t == NULL) {
            return false;
        } else if (isSame(s, t)) {
            return true;
        } else {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
    bool isSame(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) {
            return true;
        } else if (s == NULL || t == NULL) {
            return false;
        } else if (s->val != t->val) {
            return false;
        } else {
            return isSame(s->left, t->left) && isSame(s->right, t->right);
        }
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return t == NULL;
        }
        if (isSame(s, t)) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSame(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) {
            return true;
        } else if (s == NULL || t == NULL) {
            return false;
        } else if (s->val != t->val) {
            return false;
        }
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};
