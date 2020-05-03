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
        stack<TreeNode*> st;
        stringstream enc;
        while (root) {
            enc << root->val << ',';
            st.push(root);
            root = root->left;
        }
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur->right) {
                cur = cur->right;
                while (cur) {
                    enc << cur->val << ',';
                    st.push(cur);
                    cur = cur->left;
                }
            }
        }
        string enc_res = enc.str();
        if (enc_res.length() > 0) {
            enc_res.pop_back();
        }
        return enc_res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return NULL;
        }
        string cur_str = "";
        stringstream ss(data);
        TreeNode* root = NULL;
        int parent_val = INT_MAX;
        stack<pair<TreeNode*, int>> st; // parent node and upper bound of val in parent-as-the-root tree
        while (getline(ss, cur_str, ',')) {
            TreeNode* cur = new TreeNode(stoi(cur_str));
            if (!root) {
                root = cur;
                st.emplace(cur, INT_MAX);
            } else { // st will not be empty
                pair<TreeNode*, int> parent = st.top();
                if (cur->val < parent.first->val) {
                    parent.first->left = cur;
                    // Upper bound is updated when going left
                    st.emplace(cur, parent.first->val);
                } else if (cur->val > parent.first->val) {
                    while (cur->val > parent.second) {
                        st.pop();
                        parent = st.top();
                    }
                    parent.first->right = cur;
                    // Inheret upper bound from parent when going right
                    st.emplace(cur, parent.second);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
