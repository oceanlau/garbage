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
    void _dfs(TreeNode* root, int col, int row, unordered_map<int, map<int, set<int>>>& cols, int& min_col) {
        if (col < min_col) {
            min_col = col;
        }
        cols[col][row].insert(root->val);
        if (root->left) {
            _dfs(root->left, col - 1, row + 1, cols, min_col);
        }
        if (root->right) {
            _dfs(root->right, col + 1, row + 1, cols, min_col);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        int row = 0;
        int col = 0;
        int min_col = 0;
        unordered_map<int, map<int, set<int>>> cols;
        _dfs(root, col, row, cols, min_col);
        vector<vector<int>> result;
        int col_cnt = cols.size();
        while (col_cnt > 0) {
            map<int, set<int>> rows = cols[min_col];
            vector<int> column;
            for (auto row : rows) {
                column.insert(column.end(), row.second.begin(), row.second.end());
            }
            result.push_back(column);
            min_col ++;
            col_cnt --;
        }
        return result;
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
private:
    void _dfs(TreeNode* node, int col, int row, unordered_map<int, map<int, set<int>>>& m, int& left) {
        if (!node) {
            return;
        }
        m[col][row].insert(node->val);
        left = min(left, col);
        _dfs(node->left, col - 1, row + 1, m, left);
        _dfs(node->right, col + 1, row + 1, m, left);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col offset -> list pair of row id and value (sort later)
        // col offset -> (row -> set)
        unordered_map<int, map<int, set<int>>> m;
        // use map of map would be so much easier
        int left = 0;
        _dfs(root, 0, 0, m, left);
        vector<vector<int>> res;
        for (int i = 0; i < m.size(); i ++) {
            vector<int> col;
            for (const auto p : m[i + left]) {
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
