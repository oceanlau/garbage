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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l == r) {
            return new TreeNode(nums[l]);
        }
        int mid = l + ((r - l) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        if (mid > l) {
            root->left = sortedArrayToBST(nums, l, mid - 1);
        }
        if (mid < r) {
            root->right = sortedArrayToBST(nums, mid + 1, r);
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};
