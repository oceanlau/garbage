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
    int _dfs(TreeNode* node, int presum, unordered_map<int, int>& presums, const int sum) {
        presum += node->val;
        int cnt = presums[presum - sum];
        presums[presum] ++;
        if (node->left) {
            cnt += _dfs(node->left, presum, presums, sum);
        }
        if (node->right) {
            cnt += _dfs(node->right, presum, presums, sum);
        }
        presums[presum] --;
        return cnt;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        unordered_map<int, int> presums;
        presums[0] = 1;
        // Number of paths ending at this node and all children node
        return _dfs(root, 0, presums, sum);
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
    int _dfs(unordered_map<int, int>& presum, TreeNode* cur, int last_sum, int sum) {
        if (cur == NULL) {
            return 0;
        }
        int num = 0;
        last_sum += cur->val;
        if (presum[last_sum - sum] > 0) {
            num += presum[last_sum - sum];
        }
        presum[last_sum] ++;
        num += _dfs(presum, cur->left, last_sum, sum);
        num += _dfs(presum, cur->right, last_sum, sum);
        presum[last_sum] --;
        return num;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        //presum可能出现多次，所以不能用unordered_set，要用counter
        //unordered_set<int> presum;
        
        // super careful here! Dont forget the 0 starting from root!
        unordered_map<int, int> presum {{0, 1}};
        return _dfs(presum, root, 0, sum);
    }
};

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
