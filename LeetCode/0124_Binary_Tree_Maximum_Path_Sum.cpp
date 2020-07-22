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
    int maxParentToChildPathSumContaining(TreeNode* node, int& maxSum) {
        int l_child = 0;
        int r_child = 0;
        if (node->left) {
            l_child = max(l_child, maxParentToChildPathSumContaining(node->left, maxSum));
        }
        if (node->right) {
            r_child = max(r_child, maxParentToChildPathSumContaining(node->right, maxSum));
        }
        int maxParentToChildPathSum = max(l_child, r_child) + node->val;
        maxSum = max(maxSum, maxParentToChildPathSum);
        maxSum = max(maxSum, l_child + r_child + node->val);
        return maxParentToChildPathSum;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int maxSum = INT_MIN;
        maxParentToChildPathSumContaining(root, maxSum);
        return maxSum;
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
    int _max_path_sum_include(TreeNode* node, int& max_sum) {
        if (node == NULL) {
            return 0;
        }
        int l = _max_path_sum_include(node->left, max_sum);
        int r = _max_path_sum_include(node->right, max_sum);
        if (l < 0) {
            l = 0;
        }
        if (r < 0) {
            r = 0;
        }
        max_sum = max(l + node->val, max_sum);
        max_sum = max(r + node->val, max_sum);
        max_sum = max(l + r + node->val, max_sum);
        return max(l, r) + node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = root->val;
        _max_path_sum_include(root, max_sum);
        return max_sum;
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
    int max_sum_with_node(TreeNode* node, int& max_sum) {
        if (node == NULL) {
            return 0;
        }
        int max_from_node = node->val;
        int l = max_sum_with_node(node->left, max_sum);
        max_from_node = max(node->val + l, max_from_node);
        int r = max_sum_with_node(node->right, max_sum);
        max_from_node = max(node->val + r, max_from_node);
        
        int lr = l + node->val + r;
        max_sum = max(max_sum, lr);
        max_sum = max(max_sum, max_from_node);
        
        return max_from_node;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int max_sum = INT_MIN;
        max_sum_with_node(root, max_sum);
        return max_sum;
    }
};

//84% 66%
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
    
    int maxPathSumFinder(TreeNode* node, int& maxSum) {
        if (node == NULL) {
            return 0;
        }
        int l = maxPathSumFinder(node->left, maxSum);
        int r = maxPathSumFinder(node->right, maxSum);
        int maxChildSum = node->val + max(l, r);
        if (node->val > maxChildSum) {
            maxChildSum = node->val;
        }
        int maxCurSum = max(maxChildSum, node->val + l + r);
        //use node / node - node->left / node - node->right / node->left - node - node->right to update maxSum
        if (maxCurSum > maxSum) {
            maxSum = maxCurSum;
        }
        //return the max of node - node->left / node - node->right for future potential maximum
        return maxChildSum;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumFinder(root, maxSum);
        return maxSum;
    }
};
