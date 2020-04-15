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
    unordered_map<int, int> post_m;
    
    TreeNode* build(vector<int>& pre, vector<int>& post, int pre_l, int pre_r, int post_l, int post_r) {
        TreeNode* root = new TreeNode(pre[pre_l]);
        // always assume left child (in fact, could be right)
        int left_l = pre_l + 1;
        if (left_l > pre_r) {
            return root;
        }
        int left_l_in_post = post_m[pre[left_l]];
        int left_child_len = left_l_in_post - post_l + 1;
        int left_r = left_l + left_child_len - 1;
        int left_r_in_post = post_m[pre[left_r]]; // this is not post_l!!!
        root->left = build(pre, post, left_l, left_r, post_l, left_l_in_post);
        
        int right_l = left_r + 1;
        if (right_l > pre_r) {
            return root;
        }
        int right_l_in_post = post_m[pre[right_l]]; // or post_r - 1?
        int right_r = pre_r;
        int right_r_in_post = post_m[pre[right_r]]; // this is not left_l_in_post + 1!
        root->right = build(pre, post, right_l, right_r, left_l_in_post + 1, right_l_in_post);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for (int i = 0; i < post.size(); i ++) {
            post_m[post[i]] = i;
        }
        return build(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }
};
