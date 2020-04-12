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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> df;
        while (root) {
            df.push(root);
            root = root->left;
        }
        while (!df.empty()) {
            TreeNode* cur = df.top();
            df.pop();
            inorder.push_back(cur->val);
            TreeNode* right = cur->right;
            while (right) {
                df.push(right);
                right = right->left;
            }
        }
        return inorder;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (!st.empty()) {//actually useless
                root = st.top();
                st.pop();
                res.push_back(root->val);
                root = root->right;
            }            
        }
        return res;
    }
};
