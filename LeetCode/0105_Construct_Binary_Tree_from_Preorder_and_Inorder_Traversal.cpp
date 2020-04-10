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
    TreeNode* _build(vector<int>& preorder, int& start, vector<int>& inorder, int i, int j) {
        int pivot = preorder[start];
        TreeNode* root = new TreeNode(preorder[start]);
        //find doesnot include the last el
        auto it = find(inorder.begin() + i, inorder.begin() + j + 1, preorder[start]);
        start ++;
        if (it - inorder.begin() != i) {
            root->left = _build(preorder, start, inorder, i, it - inorder.begin() - 1);
        }
        if (it - inorder.begin() != j) {
            root->right = _build(preorder, start, inorder, it - inorder.begin() + 1, j);
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        int start = 0;
        return _build(preorder, start, inorder, 0, inorder.size() - 1);
    }
};
//92% 23%
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
    int _build(TreeNode*& node, vector<int>& preorder, int p_idx, vector<int>& inorder, int i_start, int i_end) {
        if (p_idx >= preorder.size()) {
            return p_idx;
        }
        int pivot_val = preorder[p_idx++];
        node = new TreeNode(pivot_val);
        auto it = find(inorder.begin() + i_start, inorder.begin() + i_end + 1, pivot_val);
        int pivot_pos = it - inorder.begin();
        if (pivot_pos > i_start) {
            p_idx = _build(node->left, preorder, p_idx, inorder, i_start, pivot_pos - 1);
        }
        if (pivot_pos < i_end) {
            p_idx = _build(node->right, preorder, p_idx, inorder, pivot_pos + 1, i_end);
        }
        //Careful
        return p_idx;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        _build(root, preorder, 0, inorder, 0, inorder.size() - 1);
        return root;
    }
};

// 80% 95%
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
    int preorder_idx = 0;
    TreeNode* _build_tree(vector<int>& preorder, vector<int>& inorder, int i, int j) {
        int root_val = preorder[preorder_idx];
        TreeNode* node = new TreeNode(root_val);
        if (preorder_idx == preorder.size() - 1){
            return node;
        }
        int k = i;
        for (; k <= j; k ++) {
            if (inorder[k] == root_val) {
                break;
            }
        }
        if (k-i == 0) {
            node->left = NULL;
        } else {
            preorder_idx ++;
            node->left = _build_tree(preorder, inorder, i, k-1);
        }
        if (j-k == 0) {
            node->right = NULL;
        } else {
            preorder_idx ++;
            node->right = _build_tree(preorder, inorder, k+1, j);
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        TreeNode* node = _build_tree(preorder, inorder, 0, inorder.size() - 1);
        return node;
    }
};
