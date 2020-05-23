// if we pass down range, we may skip good sub bst tree
// we need reverse thinking, children return the range, parent determine if it is a root of a bst
// return current child bst size, -1 means not a bst, 0 means it is NULL node
class Solution {
private:
    vector<int> bstsize(TreeNode* node, int& largest) {
        if (!node) {
            // min max for easy handling for parent
            return {0, INT_MAX, INT_MIN};
        }
        
        vector<int> l = bstsize(node->left, largest);
        vector<int> r = bstsize(node->right, largest);
        if (l[0] == -1 || r[0] == -1) {
            return {-1, -1, -1};
        }
        if ((l[0] == 0 || l[2] < node->val) && (r[0] == 0 || r[1] > node->val)) {
            largest = max(1 + l[0] + r[0], largest);
            return {1 + l[0] + r[0], min(node->val, l[1]), max(node->val, r[2])};
        }
        return {-1, -1, -1};
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        int largest = 0;
        bstsize(root, largest);
        return largest;
    }
};
