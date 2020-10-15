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
    class BSTIterator {
    private:
        stack<TreeNode*> _st;
        bool _ltor;
    public:
        BSTIterator(TreeNode* root, bool ltor) : _ltor(ltor) {
            if (_ltor) {
                while (root) {
                    _st.push(root);
                    root = root->left;
                }
            } else {
                while (root) {
                    _st.push(root);
                    root = root->right;
                }
            }
        };
        int operator* () {
            return _st.top()->val;
        }
        void operator++ (int) {
            TreeNode* cur = _st.top();
            _st.pop();
            if (_ltor) {
                if (cur->right) {
                    cur = cur->right;
                    while (cur) {
                        _st.push(cur);
                        cur = cur->left;
                    }
                }
            } else {
                if (cur->left) {
                    cur = cur->left;
                    while (cur) {
                        _st.push(cur);
                        cur = cur->right;
                    }
                }
            }
        }
    };
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l (root, true);
        BSTIterator r (root, false);
        while (*l != *r) {
            int sum = *l + *r;
            if (sum == k) {
                return true;
            } else if (sum < k) {
                l ++;
            } else {
                r ++;
            }
        }
        return false;
    }
};
