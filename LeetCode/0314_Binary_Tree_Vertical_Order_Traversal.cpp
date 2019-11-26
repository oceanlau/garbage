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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        unordered_map<int, vector<int>> col_map;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int min_col = INT_MAX;
        while (q.size() != 0) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            if (cur.second < min_col) {
                min_col = cur.second;
            }
            if (col_map.find(cur.second) == col_map.end()) {
                col_map[cur.second] = vector<int> {cur.first->val};
            } else {
                col_map[cur.second].push_back(cur.first->val);
            }
            if (cur.first->left) {
                q.push(make_pair(cur.first->left, cur.second - 1));
            }
            if (cur.first->right) {
                q.push(make_pair(cur.first->right, cur.second + 1));
            }
        }
        vector<vector<int>> res (col_map.size(), vector<int> {});
        for (int i = 0; i < res.size(); i++) {
            res[i] = col_map[min_col + i];
        }
        return res;
    }
};
