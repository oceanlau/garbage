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
    vector<vector<int>> levelOrder(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        vector<vector<int>> res;
        int depth = 0;
        while (root) {
            st.emplace(root, depth);
            res.push_back({root->val});
            root = root->left;
            depth ++;
        }
        while (!st.empty()) {
            pair<TreeNode*, int> p = st.top();
            st.pop();
            if (p.first->right) {
                TreeNode* cur = p.first->right;
                int depth = p.second + 1;
                while (cur) {
                    st.emplace(cur, depth);
                    if (res.size() < depth + 1) {
                        res.push_back({cur->val});
                    } else {
                        res[depth].push_back(cur->val);
                    }
                    cur = cur->left;
                    depth ++;
                }
            }
        }
        return res;
    }
};
