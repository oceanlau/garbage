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
    void _dfs(TreeNode* node, double& target, int& closest_val, double& closest_dist) {
        double current_dist = -1;
        if (node->val >= target) {
            current_dist = node->val - target;
            if (closest_dist == -1 || current_dist < closest_dist) {
                closest_dist = current_dist;
                closest_val = node->val;
            }
            if (closest_dist != 0 && node->left) {
                _dfs(node->left, target, closest_val, closest_dist);
            }
        } else {
            current_dist = target - node->val;
            if (closest_dist == -1 || current_dist < closest_dist) {
                closest_dist = current_dist;
                closest_val = node->val;
            }
            if (node->right) {
                _dfs(node->right, target, closest_val, closest_dist);
            }
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        int closest_val = root->val;
        double closest_dist = -1;
        _dfs(root, target, closest_val, closest_dist);
        return closest_val;
    }
};
