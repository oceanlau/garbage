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
    void _dfs(TreeNode* node, double target, int k, list<int>& closest) {
        if (node->left) {
            _dfs(node->left, target, k, closest);
        }
        
        if (closest.size() < k) {
            closest.push_back(node->val);
        } else {
            double first_distance = target - closest.front();
            if (first_distance <= 0) {
                return;
            }
            double cur_distance = fabs(node->val - target);
            if (cur_distance >= first_distance) {
                return;
            }
            closest.pop_front();
            closest.push_back(node->val);
        }
        if (node->right) {
            _dfs(node->right, target, k, closest);
        }
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        list<int> closest;
        _dfs(root, target, k, closest);
        return vector<int> (closest.begin(), closest.end());
    }
};
