/// fixed 71% 88%
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> lvl;
        lvl.push(root);
        while (lvl.size() != 0) {
            int lvl_size = lvl.size();
            double sum = 0.0;
            int lvl_size_avg = lvl_size;
            while (lvl_size != 0) {
                TreeNode* cur = lvl.front();
                sum += cur->val;
                lvl.pop();
                if (cur->left != NULL) {
                    lvl.push(cur->left);
                }
                if (cur->right != NULL) {
                    lvl.push(cur->right);
                }
                lvl_size --;
            }
            res.push_back(sum / lvl_size_avg);
        }
        return res;
    }
};

//precision bug
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> lvl;
        lvl.push(root);
        while (lvl.size() != 0) {
            int lvl_size = lvl.size();
            double avg = 0.0;
            double lvl_size_avg = lvl_size;
            while (lvl_size != 0) {
                TreeNode* cur = lvl.front();
                avg += cur->val / lvl_size_avg;
                lvl.pop();
                if (cur->left != NULL) {
                    lvl.push(cur->left);
                }
                if (cur->right != NULL) {
                    lvl.push(cur->right);
                }
                lvl_size --;
            }
            res.push_back(avg);
        }
        return res;
    }
};
