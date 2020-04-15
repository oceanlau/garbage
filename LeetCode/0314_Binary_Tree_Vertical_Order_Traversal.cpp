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
        if (!root) {
            return {};
        }
        unordered_map<int, vector<int>> col_map;
        queue<pair<int, TreeNode*>> q;
        q.emplace(0, root);
        int start = INT_MAX;
        int end = INT_MIN;
        while (!q.empty()) {
            pair<int, TreeNode*> cur = q.front();
            q.pop();
            if (cur.first < start) {
                start = cur.first;
            }
            if (cur.first > end) {
                end = cur.first;
            }
            col_map[cur.first].push_back(cur.second->val);
            if (cur.second->left) {
                q.emplace(cur.first - 1, cur.second->left);
            }
            if (cur.second->right) {
                q.emplace(cur.first + 1, cur.second->right);
            }
        }
        vector<vector<int>> res;
        while (start <= end) {
            res.push_back(col_map[start]);
            start ++;
        }
        return res;
    }
};

//wrong thinking
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
        if (!root) {
            return {};
        }
        stack<pair<int, TreeNode*>> dfs_st;
        unordered_map<int, vector<int>> res_m;
        res_m[0].push_back(root->val);
        dfs_st.push(make_pair(0, root));
        int start = 0;
        int end = 0;
        while (!dfs_st.empty()) {
            pair<int, TreeNode*> cur_pair = dfs_st.top();
            while (cur_pair.second->left) {
                cur_pair.first --;
                TreeNode** lastleft = &(cur_pair.second->left);
                cur_pair.second = cur_pair.second->left;
                *lastleft = NULL;
                if (cur_pair.first < start) {
                    start = cur_pair.first;
                }
                res_m[cur_pair.first].push_back(cur_pair.second->val);
                dfs_st.push(make_pair(cur_pair.first, cur_pair.second));
            }
            cur_pair = dfs_st.top();
            dfs_st.pop();
            if (cur_pair.second->right) {
                cur_pair.first ++;
                if (cur_pair.first > end) {
                    end = cur_pair.first;
                }
                res_m[cur_pair.first].push_back(cur_pair.second->right->val);
                dfs_st.push(make_pair(cur_pair.first, cur_pair.second->right));
            }
        }
        vector<vector<int>> results;
        while (start <= end) {
            results.push_back(res_m[start]);
            start ++;
        }
        return results;
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
