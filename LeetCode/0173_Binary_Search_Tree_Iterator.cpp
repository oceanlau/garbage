/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> _st;
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            _st.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = _st.top();
        _st.pop();
        int res = node->val;
        node = node->right;
        while (node) {
            _st.push(node);
            node = node->left;
        }
        return res;        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
