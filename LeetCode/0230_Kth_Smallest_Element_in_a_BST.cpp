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
    TreeNode* _inorder(TreeNode* root, int& k) {
        if (!root) {
            return NULL;
        }
        TreeNode* target = _inorder(root->left, k);
        if (target) {
            return target;
        }
        if (--k == 0) {
            return root;
        }
        return _inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return _inorder(root, k)->val;
    }
};

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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (root) {
            st.push(root);
            root = root->left;
        }
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (--k == 0) {
                return cur->val;
            }
            if (cur->right) {
                cur = cur->right;
                while(cur) {
                    st.push(cur);
                    cur = cur->left;
                }
            }
        }
        return NULL;
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
    int kthSmallest(TreeNode* root, int k) {
        int target;
        dfs(root, k, target);
        return target;
    }
    void dfs(TreeNode* node, int& k, int& target) {
        if (node == NULL) {
            return;
        }
        dfs(node->left, k, target);
        if (k == 0) {
            return;
        } else if (--k == 0) {
            target = node->val;
            return;
        }
        dfs(node->right, k, target);
    }
};
