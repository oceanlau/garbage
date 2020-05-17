/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) {
            return "";
        }
        queue<Node*> q;
        q.push(root);
        stringstream ss;
        while (!q.empty()) {
            /*
            int lvl_size = q.size();
            while (lvl_size) {*/
                Node* node = q.front();
                q.pop();
                if (node) {
                    ss << node->val << ',';
                    for (int i = 0; i < node->children.size(); i++) {
                        q.push(node->children[i]);
                    }
                    //fences
                    q.push(NULL);
                } else {
                    ss << "n,";
                }
                /*lvl_size --;
            }*/
        }
        return ss.str();
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.length() == 0) {
            return NULL;
        }
        stringstream ss(data);
        string value = "";
        getline(ss, value, ',');
        Node* root = new Node(stoi(value));
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            while (getline(ss, value, ',') && value != "n") {
                Node* newnode = new Node(stoi(value));
                node->children.push_back(newnode);
                q.push(newnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
