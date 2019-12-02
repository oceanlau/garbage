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
    void _dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (node->left) {
            parents[node->left] = node;
            _dfs(node->left, parents);
        }
        if (node->right) {
            parents[node->right] = node;
            _dfs(node->right, parents);
        }
    }
    void _dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parents, unordered_set<TreeNode*>& seen, int k, vector<int>& res) {
        if (k == 0) {
            res.push_back(node->val);
            return;
        }
        if (node->left && !seen.count(node->left)) {
            seen.insert(node->left);
            _dfs(node->left, parents, seen, k - 1, res);
        }
        if (node->right && !seen.count(node->right)) {
            seen.insert(node->right);
            _dfs(node->right, parents, seen, k - 1, res);
        }
        if (parents[node] && !seen.count(parents[node])) {
            seen.insert(parents[node]);
            _dfs(parents[node], parents, seen, k - 1, res);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == NULL) {
            return {};
        }
        // find the path from root to target, record vector<node*, distance_to_target> including target itself
        // do dfs on every one in this vector till (k -= distance_to_target) becomes zero
        // maybe working, bad for interview followup
        // normal way:
        // traverse all nodes, build a map of node to parent
        // do a bfs or dfs from target to all child and parent (need to record seen nodes) till k becomes zero
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] == NULL;
        _dfs(root, parents);
        vector<int> res;
        unordered_set<TreeNode*> seen;
        seen.insert(target);
        _dfs(target, parents, seen, K, res);
        return res;
    }
};
