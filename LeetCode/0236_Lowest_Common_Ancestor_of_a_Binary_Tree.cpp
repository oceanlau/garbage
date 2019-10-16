//73% 76%
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
    int _dfs(TreeNode*& res, TreeNode* node, TreeNode* p, TreeNode* q) {
        int ind = 0;
        if (node->val == p->val) {
            ind ++;
        }
        if (node->val == q->val) {
            ind ++;
        }
        if (node->left != NULL) {
            ind += _dfs(res, node->left, p, q);
        }
        if (ind < 2 && node->right != NULL) {
            ind += _dfs(res, node->right, p, q);
        }
        if (res == NULL && ind >= 2) {
            res = node;
        }
        return ind;
    }
    //int indicator 0 - not found, 1 - found 1, 2 found 2 _dfs(*res, node, p, q) {
        // this_ind = 0
        // if node = p, this id++
        // if node = q, this id++
        // if l exists idl = _dfs(l)
        // if r exists idl = _dfs(r)
        // if res == null && id sum == 2, res = this node
        // return id sum
        // 
    //}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        if (_dfs(res, root, p, q) >= 2) {
            return res;
        }
        return NULL;
    }
};
