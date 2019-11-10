//bfs, not clean? 62% 100%

//dfs, not clean, 5% 7%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string _dfs(TreeNode* node) {
        if (node == NULL) {
            return "null,";
        } else {
            string s = to_string(node->val) + ',';
            s += _dfs(node->left);
            s += _dfs(node->right);
            return s;
        }
    }
    
    int _ddfs(TreeNode*& node, string data, int i) {
        if (i == data.length()) {
            node = NULL;
            return i;
        }
        int j = i;
        while (data[j] != ',') {
            j ++;
        }
        string cur = data.substr(i, j - i);
        if (cur == "null") {
            node = NULL;
            return j + 1;
        }
        node = new TreeNode(stoi(cur));
        j++;
        if (j == data.length()) {
            node->left = NULL;
        } else {
            j = _ddfs(node->left, data, j);
        }
        if (j == data.length()) {
            node->right = NULL;
        } else {
            j = _ddfs(node->right, data, j);
        }
        return j;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return _dfs(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        _ddfs(root, data, 0);//pass by ref or return node
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
