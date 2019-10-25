// 97% 19%
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
    int _dfs(TreeNode* node, int sum, unordered_map<int, int>& sum_history, int current_sum) {
        if (node == NULL) {
            return 0;
        }
        int found = 0;
        current_sum += node->val;
        if (sum_history.find(current_sum - sum) != sum_history.end()) {
            found += sum_history[current_sum - sum];
        }
        //after above, in case sum == 0
        sum_history[current_sum]++;
        found += _dfs(node->left, sum, sum_history, current_sum) + _dfs(node->right, sum, sum_history, current_sum);
        sum_history[current_sum]--;
        return found;
        
    }
public:
    int pathSum(TreeNode* root, int sum) {
        // give root node a chance!
        unordered_map<int, int> sum_history {{0, 1}};
        return _dfs(root, sum, sum_history, 0);
    }
};
