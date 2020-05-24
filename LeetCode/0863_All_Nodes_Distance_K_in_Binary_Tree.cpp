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
    bool _find(TreeNode* node, TreeNode*& target, vector<TreeNode*>& parents) {
        parents.push_back(node);
        if (node == target) {
            return true;
        }
        if (node->left) {
            if (_find(node->left, target, parents)) {
                return true;
            }
        }
        if (node->right) {
            if (_find(node->right, target, parents)) {
                return true;
            }
        }
        parents.pop_back();
        return false;
    }
    void _dfs(TreeNode* node, TreeNode* visited_child, int d, int& K, vector<int>& res) {
        if (d == K) {
            res.push_back(node->val);
            return;
        }
        if (node->left && node->left != visited_child) {
            _dfs(node->left, NULL, d + 1, K, res);
        }
        if (node->right && node->right != visited_child) {
            _dfs(node->right, NULL, d + 1, K, res);
        }
    }
    void _start_dfs(vector<TreeNode*>& parents, int& K, vector<int>& res) {
        int d = 0;
        while(parents.size() > 1 && d <= K) {
            TreeNode* visited_child = parents.back();
            parents.pop_back();
            _dfs(parents.back(), visited_child, d, K, res);
            d ++;
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> parents;
        _find(root, target, parents);
        parents.push_back(NULL);
        vector<int> res;
        _start_dfs(parents, K, res);
        return res;
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
