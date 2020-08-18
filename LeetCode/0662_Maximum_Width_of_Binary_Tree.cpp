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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        int max_width = 0;
        while (!q.empty()) {
            int q_size = q.size();
            int left = INT_MAX;
            while (q_size > 0) {
                auto cur = q.front();
                q.pop();
                if (cur.second < left) {
                    left = cur.second;
                }
                // To avoid overflow
                cur.second -= left;
                if (cur.first->left) {
                    q.emplace(cur.first->left, 2 * cur.second);
                }
                if (cur.first->right) {
                    q.emplace(cur.first->right, 2 * cur.second + 1);
                }
                // because of the -= left above
                max_width = max(max_width, cur.second - 0 + 1);
                q_size --;
            }
        }
        return max_width;
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int maxwidth = 1;
        while (!q.empty()) {
            int q_size = q.size();
            int left = -1;
            
            //find min of cur row, all subtract it to avoid int overflow
            pair<TreeNode*, int> cur = q.front();
            int min_cur = cur.second;
            
            while (q_size > 0) {
                cur = q.front();
                TreeNode* cur_node = cur.first;
                q.pop();
                if (cur_node->left) {
                    int pos = 2 * (cur.second - min_cur + 1);
                    if (left == -1) {
                        left = pos;
                    } else {
                        maxwidth = max(pos - left + 1, maxwidth);
                    }
                    q.push(make_pair(cur_node->left, pos));
                }
                if (cur_node->right) {
                    int pos = 2 * (cur.second - min_cur + 1) + 1;
                    if (left == -1) {
                        left = pos;
                    } else {
                        maxwidth = max(pos - left + 1, maxwidth);
                    }
                    q.push(make_pair(cur_node->right, pos));
                }
                q_size --;
            }
        }
        return maxwidth;
    }
};
