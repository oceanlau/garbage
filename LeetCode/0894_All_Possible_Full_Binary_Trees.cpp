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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N == 0 || N % 2 == 0) {
            return {};
        }
        if (N == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode*> results;
        for (int l = 1; l < N - 1; l += 2) {
            vector<TreeNode*> leftChildFBTs = allPossibleFBT(l);
            vector<TreeNode*> rightChildFBTs = allPossibleFBT(N - 1 - l);
            for (int i = 0; i < leftChildFBTs.size(); i++) {
                for (int j = 0; j < rightChildFBTs.size(); j ++) {
                    TreeNode* root = new TreeNode(0);
                    root->left = leftChildFBTs[i];
                    root->right = rightChildFBTs[j];
                    results.push_back(root);
                }
            }
        }
        return results;
    }
};
