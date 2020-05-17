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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> lvl_nodes;
        lvl_nodes.push(root);
        int is_found = false;
        while(lvl_nodes.size() != 0) {
            //Use queue size to mark lvl end to avoid dual queue
            int lvl_cnt = lvl_nodes.size();
            while(lvl_cnt != 0) {
                TreeNode* node = lvl_nodes.front();
                lvl_nodes.pop();
                if (node->val == x || node->val == y) {
                    if (is_found) {
                        return true;
                    }
                    is_found = true;
                }
                // Special check for the same parent rule
                if (node->left != NULL && node->right != NULL) {
                    if ((node->left->val == x && node->right->val == y)
                        || (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                if (node->left != NULL) {
                    lvl_nodes.push(node->left);
                }
                if (node->right != NULL) {
                    lvl_nodes.push(node->right);
                }
                lvl_cnt--;
            }
            if (is_found) {
                return false;
            }
        }
        return false;
    }
};

// 73% 100%
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> lvl_nodes;
        lvl_nodes.push(root);
        int is_found = false;
        while(lvl_nodes.size() != 0) {
            //Use queue size to mark lvl end to avoid dual queue
            int lvl_cnt = lvl_nodes.size();
            while(lvl_cnt != 0) {
                TreeNode* node = lvl_nodes.front();
                lvl_nodes.pop();
                if (node->val == x || node->val == y) {
                    if (is_found) {
                        return true;
                    }
                    is_found = true;
                }
                // Special check for the same parent rule
                if (node->left != NULL && node->right != NULL) {
                    if ((node->left->val == x && node->right->val == y)
                        || (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                if (node->left != NULL) {
                    lvl_nodes.push(node->left);
                }
                if (node->right != NULL) {
                    lvl_nodes.push(node->right);
                }
                lvl_cnt--;
            }
            if (is_found) {
                return false;
            }
        }
        return false;
    }
};

// 73% 6%
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> lvl_nodes;
        lvl_nodes.push(root);
        int is_found = false;
        while(lvl_nodes.size() != 0) {
            queue<TreeNode*> lvl_nodes_tmp;
            while(lvl_nodes.size() != 0) {
                TreeNode* node = lvl_nodes.front();
                lvl_nodes.pop();
                if (node->val == x || node->val == y) {
                    if (is_found) {
                        return true;
                    }
                    is_found = true;
                }
                // Special check for the same parent rule
                if (node->left != NULL && node->right != NULL) {
                    if ((node->left->val == x && node->right->val == y)
                        || (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                if (node->left != NULL) {
                    lvl_nodes_tmp.push(node->left);
                }
                if (node->right != NULL) {
                    lvl_nodes_tmp.push(node->right);
                }
            }
            if (is_found) {
                return false;
            }
            lvl_nodes = lvl_nodes_tmp;
        }
        return false;
    }
};
