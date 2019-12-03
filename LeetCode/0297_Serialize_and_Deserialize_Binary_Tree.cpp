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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while (q.size() != 0) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                s += "NULL,";
            } else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = data.find(',');
        string val = data.substr(0, pos);
        TreeNode* root = NULL;
        if (val != "NULL") {
            root = new TreeNode(stoi(val));
        }
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() != 0) {
            TreeNode* node = q.front();
            q.pop();
            if (node != NULL) {
                int first_comma_pos = data.find(',', pos + 1);
                int second_comma_pos = data.find(',', first_comma_pos + 1);
                string first_val = data.substr(pos + 1, first_comma_pos - pos - 1);
                string second_val = data.substr(first_comma_pos + 1, second_comma_pos - first_comma_pos - 1);
                if (first_val == "NULL") {
                    node->left = NULL;
                } else {
                    TreeNode* left_node = new TreeNode(stoi(first_val));
                    node->left = left_node;
                    q.push(node->left);
                }
                if (second_val == "NULL") {
                    node->right = NULL;
                } else {
                    TreeNode* right_node = new TreeNode(stoi(second_val));
                    node->right = right_node;
                    q.push(node->right);
                }
                pos = second_comma_pos;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//bfs, not clean? 62% 100%
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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (q.size() > 0) {
            int q_size = q.size();
            while (q_size > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (node == NULL) {
                    res += "null,";
                } else {
                    res += to_string(node->val) + ',';
                    q.push(node->left);
                    q.push(node->right);
                }
                q_size--;
            }
        }
        return res;
    }

    int helper(string& data, int i, TreeNode*& node) {
        if (i == data.length()) {
            node = NULL;
            return i;
        }
        int end = i;
        while (data[end] != ',') {
            end ++;
        }
        string cur = data.substr(i, end - i);
        if (cur == "null") {
            node = NULL;
        } else {
            node = new TreeNode(stoi(cur));
        }
        i = end + 1;
        return i;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        int i = helper(data, 0, root);
        if (root == NULL) {
            return NULL;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (q.size() > 0) {
            int q_size = q.size();
            while (q_size > 0) {
                TreeNode* node = q.front();
                q.pop();

                i = helper(data, i, node->left);
                if (node->left != NULL) {
                    q.push(node->left);
                }
                i = helper(data, i, node->right);
                if (node->right != NULL) {
                    q.push(node->right);
                }

                q_size--;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
