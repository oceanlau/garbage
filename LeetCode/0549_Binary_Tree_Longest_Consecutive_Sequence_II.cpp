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
    // return max length of dec and inc path starting from current node.
    pair<int, int> _get_lens(TreeNode* node, int& peak) {
        if (node == NULL) {
            return {0,0};
        }
        pair<int, int> cur = {1,1};
        pair<int, int> left = _get_lens(node->left, peak);
        pair<int, int> right = _get_lens(node->right, peak);
        //considering current node, reset left and right
        if (node->left) {
            if (node->val - node->left->val != 1) {
                left.first = 0;
            }
            if (node->left->val - node->val != 1) {
                left.second = 0;
            }
        }
        if (node->right) {
            if (node->val - node->right->val != 1) {
                right.first = 0;
            }
            if (node->right->val - node->val != 1) {
                right.second = 0;
            }
        }
        cur.first = max(left.first + 1, right.first + 1);
        cur.second = max(left.second + 1, right.second + 1);
        int cur3 = max(left.first + 1 + right.second, left.second + 1 + right.first);
        peak = max(peak, cur.first);
        peak = max(peak, cur.second);
        peak = max(peak, cur3);
        return cur;
    }
public:
    int longestConsecutive(TreeNode* root) {
        int peak = 0;
        _get_lens(root, peak);
        return peak;
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
private:
    pair<int, int> _dfs(TreeNode* node, int& longest) {
        pair<int, int> dp(1, 1);// longest inc and dec path from this node
        pair<int, int> child_dp(0, 0);
        pair<int, int> max_child_dp(0, 0);
        if (node->left) {
            child_dp = _dfs(node->left, longest);
            int delta_left = node->left->val - node->val;
            if (delta_left == 1) {
                max_child_dp.first = child_dp.first;
            } else if (delta_left == -1) {
                max_child_dp.second += child_dp.second;
            }
        }
        if (node->right) {
            child_dp = _dfs(node->right, longest);
            int delta_right = node->right->val - node->val;
            if (delta_right == 1) {
                max_child_dp.first = max(child_dp.first, max_child_dp.first);
            } else if (delta_right == -1) {
                max_child_dp.second = max(child_dp.second, max_child_dp.second);
            }
        }
        dp.first += max_child_dp.first;
        dp.second += max_child_dp.second;
        longest = max(longest, dp.first + dp.second - 1);
        return dp;
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int longest = 0;
        _dfs(root, longest);
        return longest;
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
private:
    //return the longest path
    int _dfs(TreeNode* node, int delta) {
        int candidate_len_l = 0;
        int candidate_len_r = 0;
        int candidate_len_lr = 0;
        
        int delta_left = 0;
        int delta_right = 0;
        // try 2
        
        if (node->left) {
            delta_left = node->left->val - node->val;
            if (delta_left != 1 && delta_left != -1) {
                delta_left = 0;
            }
            candidate_len_l = _dfs(node->left, delta_left);
        }
        if (node->right) {
            delta_right = node->right->val - node->val;
            if (delta_right != 1 && delta_right != -1) {
                delta_right = 0;
            }
            candidate_len_r = _dfs(node->right, delta_right);
        }
        
        if (delta_left != 0 && delta_left == -delta_right) {
            candidate_len_lr = candidate_len_l + candidate_len_r - 1;
        }
        if (delta != 0) {
            if (delta_left != 0) {
                candidate_len_l += 1;
            }
            if (delta_right != 0) {
                candidate_len_r += 1;
            }
        }
        
        // try 1
            if (delta_left != 1 && delta_left != -1) {
                delta_left = 0;
            }
            if (delta != 0 && delta == delta_left) {
                candidate_len = _dfs(node->left, len, delta_left);
            } else if (delta_left != 0) {
                candidate_len = _dfs(node->left, 1, delta_left);
                candidate_len_lr += candidate_len;
            } else {
                candidate_len = _dfs(node->left, 0, delta_left);
            }
        }
        if (node->right) {
            delta_right = node->right->val - node->val;
            if (delta_right != 1 && delta_right != -1) {
                delta_right = 0;
            }
            if (delta != 0 && delta == delta_right) {
                candidate_len_r = _dfs(node->right, len, delta_right);
            } else if (delta_right != 0) {
                candidate_len_r = _dfs(node->right, 1, delta_right);
                candidate_len_lr += candidate_len_r;
            } else {
                candidate_len_r = _dfs(node->right, 0, delta_right);
            }
            
            if (node->left && delta_left !=0 && delta_left == -delta_right) {
                candidate_len = max(candidate_len_lr - 1, candidate_len);
            }
        }
        candidate_len = max(candidate_len, candidate_len_r);
        return max(len, candidate_len);
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return _dfs(root, 0);
    }
};
