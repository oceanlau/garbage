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
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> to_visit;
        TreeNode* first_swap_node = NULL;
        TreeNode* second_swap_node = NULL;
        TreeNode* node = root;
        while(node) {
            to_visit.push(node);
            node = node->left;
        }
        TreeNode* last_node = NULL;
        while(to_visit.size() > 0) {
            node = to_visit.top();
            to_visit.pop();
            if (last_node && last_node->val > node->val){
                if (!first_swap_node) {
                    first_swap_node = last_node;
                    second_swap_node = node;//maybe, need to run till the end to confirm
                } else {
                    second_swap_node = node;
                    break;
                }
            }
            last_node = node;
            
            node = node->right;
            while(node) {
                to_visit.push(node);
                node = node->left;
            }
        }
        int tmp = second_swap_node->val;
        second_swap_node->val = first_swap_node->val;
        first_swap_node->val = tmp;
    }
};
